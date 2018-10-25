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

bool is_target_older (char *target, char *dependency) {
	
	if(is_older (get_modification_date(target), get_modification_date(dependency))) {
		return true;	
	} else {
		return false;
	}
}


void execute_actions (int position) {

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

			target_older = is_target_older (target->target, this_dependency);
			
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

		