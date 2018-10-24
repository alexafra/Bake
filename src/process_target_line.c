#include "bake.h"


// /*
// where zero-or-more whitespace characters (spaces and tabs) may appear before and after the ':' character. The first targetname found in a file is the default target, 
// and is the one to be rebuilt if no other targetname is provided on bake's command-line (see later).

// If the targetname represents a file in the current working directory, then the file's modification date is used as the date of the target. 
// Otherwise, the target is assumed to be created by the target's actions, if they are successfully executed.

// Dependencies: Each target line may provide zero-or-more dependencies. If there are no dependencies, then the target requires rebuilding.
//  There are three types of dependencies - ones that identify existing files on disk, ones that identify other targets, and ones that identify 
//  a web-based URL (a Uniform Resource Locator). If any dependency does not exist, or has been modified more recently that its target, then the target requires rebuilding (see Action lines).


// URL dependencies: if a dependency looks like an simple URL (it commences with the pattern file://, http://, or https://) it is assumed to define a URL
//  to be requested to determine if the associated file exists and has been modified more recently that the current target.
// bake must use the external utility curl to determine if the file (indicated by the URL) has been modified more recently than the current target. 
// curl is usually installed on macOS or Linux machines, and is available from curl.haxx.se. Note that bake should not download the indicated file, 
// just use curl's --head option to find the modification date. However, any target's action may choose to explicitly download a file
// . It is an error if curl reports if a URL-based dependency is not found; it is not sought as a target. 

// */

// time_t * get_modification_date(char *filename) {
	
// 	//THIS COMPILES BUT MAY NOT WORK... NOT TESTED
// 	time_t *filetime;
// 	struct stat attrib;
// 	if(stat(filename, &attrib) != 0) {
// 		perror("Stat fail");
	
// 	} else {

// 	filetime = &attrib.st_mtime;
// 	return filetime;
// 	}
// }

// bool is_more_recent(time_t *time1, time_t *time2) {
	
// 	//THIS HAS PROBLEMS WITH 'makes integer from pointer without a cast'

// 	//compare the times here...

// 	if(difftime(&time1, &time2) > 0) {
// 		return true;
// 	}
// 	return false;
// }

char * get_directory() {
	//THIS WORKS!!!!!!

	char *cwd = malloc(PATH_MAX);
	if(getcwd(cwd, PATH_MAX * sizeof(cwd)) != NULL) {
		return cwd;
	} else {
		perror("getcwd() error");
		exit(EXIT_FAILURE); //Do you even do this here?
	}
}

bool is_in_current_dir(char *targetname) {
	
	//THIS WORKS
	struct stat buf;
	return (stat(targetname, &buf) == 0);  
}

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

bool startswith(char *url, char *dep) {

	//THIS WORKS
	//Arbitrary function for checking start of strings
	if(strncmp(url, dep, strlen(url)) == 0) {
		return true;
	} else {
		return false;	
	}
	 
}		

bool check_if_url(char *dependency) {
	
	//THIS WORKS
	//Check to see whether the dependency looks like a url
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


int is_dependency_target (char * dependency) {

	bool is_target = false;
	int number_targets = get_num_targets();
	int i;
	for (i = 0; i < number_targets; ++i ) {
		if (strcmp(dependency, targets[i]->target) == 0) {
			is_target = true;
			return i;
		}
	}
	return -1;
}

bool is_dependency_url (char * dependency) {
	return true;

}

bool is_url_accessible (char *dependency) {
	return true;
}

bool is_dependency_file (char * dependency) {
	return true;
}

void execute_actions (int position) {

}

bool is_target_older (char *target, char *depencency) {
	return true;
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

		
// 	if(target was modified more recently than all dependencies) {
			
// 		do nothing with this entire line--ie exit;
		
// 	} else {

// 		run action_line on SHELL;
// 	}	

// }	

// char ** isolate_dependencies(char *rest_of_line) {
// 	//split up all dependencies and return an array of char pointers
// }

// //If(no )


// process_target_line(char *firstword, char *rest_of_line, int *no_variables, int *variable_length) {

// 	create structure filled with (MAYBE PUT THIS OUTSIDE OF THIS FUNCTION) 
// 	- target
// 	- array of dependencies
// 	- action line 


// 	//ALGORITHM FOR THIS FUNCTION

// 	char **dependencies = isolate_dependencies(&rest_of_line);

// 	process_this_line(target, dependencies, action_line);
	

// 	//Find current directory
	

// 	/*char *curr_dir = get_current_dir_name();
// 	//need to call free() after, when using "get_current_dir_name()"

// 	if(first_target_line) {
// 		char *default_target = firstword;
// 	}

// 	struct stat file
// 	if(stat(firstword, )) 
	

// 	//we need to chop off the ":"
// 	//then we need to get the next word
// 	//then we find the latest modification date of this word (possibly using stat())
// 	//compare this with the modification date of the *firstword
// 	//if *firstword is earlier, then 


// 	if(there are no dependencies) {
// 		rebuild the target
// 	}

// 	*/
//
// }
