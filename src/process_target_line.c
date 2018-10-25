#include "bake.h"

time_t geturltime (char *url) {
	
	//Could not get curl to work, so...
	time_t timer;
	time(&timer);

	return timer;
}

int is_dependency_target (char * dependency) {

	int number_targets = get_num_targets();
	int i;
	for (i = 0; i < number_targets; ++i ) {
		if (strcmp(dependency, targets[i]->target) == 0) {
			return i;
		}
	}
	return -1;
}

bool startswith(char *url, char *dep) {

	//Arbitrary function for checking start of strings
	if(strncmp(url, dep, strlen(url)) == 0) {
		return true;
	} else {
		return false;	
	}	 
}

bool is_dependency_url (char * dependency) {
	
	//Check these three strings
	char *url1 = "file://";
	char *url2 = "http://";
	char *url3 = "https://";

	//If a url
	if(startswith(url1, dependency) || startswith(url2, dependency) || startswith(url3, dependency)) {
	
		return true;

	} else {
	//If not a url
	return false;
	}	

}

bool is_url_accessible (char *dependency) {
	//We pretend that all urls are helllll good
	return true;
}

bool is_file (char * dependency) {
	//If stat doesn't return anything, the file doesn't exist
	struct stat buf;
	if(stat(dependency, &buf) == 0) {
		return true;
	} else {
		return false;
	}
}

bool is_older (time_t time1, time_t time2) {
	
	//Compare modification dates here
	if(time1 < time2) {
		return true;
	}
	return false;
}

time_t get_modification_date (char *filename) {
	
	//Returns the modification date of file 
	time_t filetime;
	struct stat attrib;
	//If stat cannot access the file, we run error
	if(stat(filename, &attrib) != 0) {
		perror("Stat fail");
		exit(EXIT_FAILURE);
	//If it success, return the time_t value
	} else {
		filetime = attrib.st_mtime;
		return filetime;
	}
}

bool is_url_recent (char *target, char * url) {

	//Get the two time_t values and compare 
	if (is_older (get_modification_date(target), geturltime(url))) {
		return true;
	} else {
		return false;
	}
}

bool is_target_older (char *target, char *dependency) {
	
	//First get the time_t values
	time_t target_date = get_modification_date(target);
	time_t dependency_date = get_modification_date(dependency);
	bool is_target_older = is_older (target_date, dependency_date);
	
	//Then compare the values
	if (is_target_older) {
		return true;	
	} else {
		return false;
	}
}

bool execute_action (char * action) {
	
	int err = system(action);
	
	if (err < 0) {
		return false;
	} else {
		return true;
	}
	
}


// //      -i : ignore the unsuccessful termination of actions; continue executing a target's actions even if any fail.
// // 
//         -n : print (to stdout) each shell-command-sequence before it is to be executed, but do not actually execute the commands. Assume that each shell-command-sequence executes successfully. This option enables bake to simply report what it would do, without doing it.
// //      
// //      -s : execute silently, do not print each shell-command-sequence before it is executed.


void execute_actions (int position, bool i_flag, bool n_flag, bool s_flag) {

	Target * target = targets[position];
	char ** actions = target->actions;
	int num_actions = numstrings(actions);
	
	

	for (int i = 0; i < num_actions; ++i) {
		bool action_successful = true;

		if (starts_with_char(actions[i], '-')) { //fail silently

			skip_leading_space(actions[i]);

			if (!s_flag) {
				printf("%s\n", actions[i]);
			}
			

			char * new_action = strdup(actions[i]);
			int error;
			move_back(new_action, 0, 1, &error);
			skip_leading_space(new_action);

			if (!n_flag) {
				action_successful = execute_action(new_action);
			}
			


		} else if (starts_with_char(actions[i], '@')) { //dont print

			skip_leading_space(actions[i]);
			
			char * new_action = strdup(actions[i]);
			int error;
			move_back(new_action, 0, 1, &error);
			skip_leading_space(new_action);

			
			if (!n_flag) {
				action_successful = execute_action(new_action);

				if (!action_successful && !i_flag) {
					perror("\n\naction unsuccessful\n\n");
					free (variables);
					free (targets);
					exit(EXIT_FAILURE);
				}
			}

			
		} else {
			skip_leading_space(actions[i]);

			if (!s_flag) {
				printf("%s\n", actions[i]);
			}

			if (!n_flag) {
				action_successful = execute_action(actions[i]);
			
				if (!action_successful && !i_flag) {
					perror("\n\naction unsuccessful\n\n");
					free (variables);
					free (targets);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	
}




bool process_target (int pos, bool i_flag, bool n_flag, bool s_flag) {
	Target * target = targets[pos];

	int num_dependencies = numstrings(target->dependencies);

	if (num_dependencies == 0) {
		execute_actions(pos, i_flag, n_flag, s_flag);
	}

	

	bool target_file_exists = is_file(target->target);

	bool target_older = !target_file_exists;


	for (int i = 0; i < num_dependencies; ++i) {
		char * this_dependency = target->dependencies[i];

		int is_target = is_dependency_target (this_dependency);
		bool is_url = is_dependency_url (this_dependency);
		bool file_exists = is_file(this_dependency);

		if (is_target >= 0) {

			if (process_target(is_target, i_flag, n_flag, s_flag)) {
				target_older = true;
			} 

		} else if(is_url) {
			bool url_exists = is_url_accessible(this_dependency);
			if (!url_exists) {
				perror("\nERROR URL DOES NOT EXIST!\n");
				free (variables);
				free (targets);
				exit(EXIT_FAILURE);
			}
			if (target_file_exists) {
				target_older = is_url_recent (target->target, this_dependency);
			} else {
				target_older = true;
			}

			
		} else if (file_exists) {
			bool target_file_exists = is_file(target->target);
			if (target_file_exists) {
				target_older = is_target_older (target->target, this_dependency);
			} else {
				target_older = true;
			}
			

		} else {
			target_older = true;
		}


	}
	if (target_older) {
		execute_actions (pos, i_flag, n_flag, s_flag);
		return true;
	}
	return false;
	
}

void process_bake (bool i_flag, bool n_flag, bool s_flag) {

	int numtargets = get_num_targets();
	for (int i = 0; i < numtargets; ++i ) {
		process_target(i, i_flag, n_flag, s_flag);
	}

}
