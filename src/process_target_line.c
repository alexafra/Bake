#include "bake.h"


// char * get_directory() {
// 	//THIS WORKS!!!!!!

// 	char *cwd = malloc(PATH_MAX);
// 	if(getcwd(cwd, PATH_MAX * sizeof(cwd)) != NULL) {
// 		return cwd;
// 	} else {
// 		perror("getcwd() error");
// 		exit(EXIT_FAILURE); //Do you even do this here?
// 	}
// }

// time_t get_url_time(char *url) {
// 	//curl -s -v --head http://foo.com/bar/baz.pdf 2>&1 | grep '^< Last-Modified:'

// 	int pid = fork();
// 	///DUNNO HOW TO DO THIS 
// }

// bool url_exists(char *url) {

// 	CURL *curl;
// 	CURLcode isurl;

// 	curl = curl_easy_init();

// 	if(curl) {
// 		curl_easy_setopt(curl, CURLOPT_URL, url);

// 		//Dont send to stdout
// 		curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

// 		//Send request
// 		isurl = curl_easy_perform(curl);
// 		curl_easy_cleanup(curl);
// 	}

// 	return (isurl == CURLE_OK); //? 1 : 0;
// }

time_t geturltime (char *url) {
	
	//Could not get curl to work, so...
	time_t timer;
	time(&timer);

	return timer;
}

int is_dependency_target (char * dependency) {

	//bool is_target = false;
	int number_targets = get_num_targets();
	int i;
	for (i = 0; i < number_targets; ++i ) {
		if (strcmp(dependency, targets[i]->target) == 0) {
			//is_target = true;
			return i;
		}
	}
	return -1;
}

bool startswith(char *url, char *dep) {

	//THIS WORKS
	//Arbitrary function for checking start of strings
	if(strncmp(url, dep, strlen(url)) == 0) {
		return true;
	} else {
		return false;	
	}	 
}

bool is_dependency_url (char * dependency) {
	
	char *url1 = "file://";
	char *url2 = "http://";
	char *url3 = "https://";

	//If yes
	if(startswith(url1, dependency) || startswith(url2, dependency) || startswith(url3, dependency)) {
	
		return true;

	} else {
	//If not a url
	return false;
	}	

}

bool is_url_accessible (char *dependency) {
	return true;
}

bool is_dependency_file (char * dependency) {
	struct stat buf;
	if(stat(dependency, &buf) == 0) {
		return true;
	} else {
		return false;
	}
}

bool is_older (time_t time1, time_t time2) {
	
	//Compare modification dates here

	if(difftime(time1, time2) < 0) {
		return true;
	}
	return false;
}

time_t get_modification_date (char *filename) {
	
	//Returns the modification date of file 
	time_t filetime;
	struct stat attrib;
	if(stat(filename, &attrib) != 0) {
		perror("Stat fail");
		exit(EXIT_FAILURE);
	} else {

	filetime = attrib.st_mtime;
	return filetime;
	}
}

bool is_url_recent (char *target, char * url) {

	if (is_older (get_modification_date(target), geturltime(url))) {
		return true;
	} else {
		return false;
	}
}

bool is_target_older (char *target, char *dependency) {
	
	if(is_older (get_modification_date(target), get_modification_date(dependency))) {
		return true;	
	} else {
		return false;
	}
}

bool execute_action (int target_pos, int action_pos) {
	Target * target = targets[target_pos];
	char * action = target->actions[action_pos];
	char * shell = getenv("SHELL");
	if (shell == NULL) {
		shell = '/bin/bash';
	}

	pid_t pid;
	pid = fork();
	int status;
	if (pid == 0) { //chld
        if (-1 == execl(shell, action , NULL)) {
            perror("child process execve failed");
            exit (1);
        } else {
        	exit (0);
        }
    } else if (pid < 0) {
    	return false;
	} else {   
	    waitpid(pid, &status, 0);  // Parent process waits here for child to terminate.
	    if (status == 0) {
	    	return true;
	    } else {
	    	return false;
	    }
	} 

}

void execute_actions (int position) {
	Target * target = targets[pos];
	char ** actions = target->actions;
	int num_actions = num_strings(actions);
	
	

	for (int i = 0; i < num_actions; ++i) {
		bool action_successful = true;
		if (starts_with_char(actions[i], '-')) { //something specific
			skip_leading_space(actions[i]);
			action_successful = execute_action(position, i);
			if (!action_successful) {
				//do some stuff
			}

		} else if (starts_with_char(actions[i], '@')) {
			skip_leading_space(actions[i]);
			printf("%s\n", actions[i]);
			action_successful = execute_action(position, i);
			if (!action_successful) {
				//do some stuff
			}
		} else {
			skip_leading_space(actions[i]);
			action_successful = execute_action(position, i);
			if (!action_successful) {
				//do some stuff
			}
		}
	}
	
}



void process_target (int pos) {
	Target * target = targets[pos];

	int num_dependencies = numstrings(target->dependencies);

	if (num_dependencies == 0) {
		execute_actions(pos);
	}

	bool target_older = false;

	for (int i = 0; i < num_dependencies; ++i) {
		char * this_dependency = target->dependencies[i];

		int is_target = is_dependency_target (this_dependency);
		bool is_url = is_dependency_url (this_dependency);
		bool file_exists = is_dependency_file(this_dependency);

		if (is_target >= 0) {
			
			process_target(is_target);

		} else if(is_url) {
			bool url_exists = is_url_accessible(this_dependency);
			if (!url_exists) {
				perror("\n\nERROR URL DOES NOT EXIST!\n\n");
				free (variables);
				free (targets);
				exit(EXIT_FAILURE);
			}

			target_older = is_url_recent (target->target, this_dependency);
			
		} else if (file_exists) {
			target_older = is_target_older (target->target, this_dependency);

		} else {

			//Actually, if it doesn't exist, we need to run the action line (see CITS2002 description)
			perror("\n\nERROR FILE DOES NOT EXIST IN DIRECTORY!\n\n");
			free (variables);
			free (targets);
			exit(EXIT_FAILURE);
		}


	}
	if (target_older) {
		execute_actions (pos);
	}
	
}

void process_bake ( void ) {

	int numtargets = get_num_targets();
	for (int i = 0; i < numtargets; ++i ) {
		process_target(i);
	}

}

		