#include "bake.h"


time_t * get_modification_date(char *filename) {
	
	//THIS COMPILES BUT MAY NOT WORK... NOT TESTED
	time_t *filetime;
	struct stat attrib;
	if(stat(filename, &attrib) != 0) {
		perror("Stat fail");
	
	} else {

	filetime = &attrib.st_mtime;
	return filetime;
	}
}

bool is_more_recent(time_t *time1, time_t *time2) {
	
	//THIS HAS PROBLEMS WITH 'makes integer from pointer without a cast'

	//compare the times here...

	if(difftime(&time1, &time2) > 0) {
		return true;
	}
	return false;
}

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

time_t get_url_time(char *url) {
	//curl -s -v --head http://foo.com/bar/baz.pdf 2>&1 | grep '^< Last-Modified:'

	int pid = fork();
	///DUNNO HOW TO DO THIS 
}

bool url_exists(char *url) {

	CURL *curl;
	CURLcode isurl;

	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);

		//Dont send to stdout
		curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

		//Send request
		isurl = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	return (isurl == CURLE_OK); //? 1 : 0;
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
