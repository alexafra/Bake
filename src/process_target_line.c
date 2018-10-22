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
char * get_modification_date(char *filename) {
	struct stat attrib;
	stat(filename, &attrib);
	char time[20];
	strftime(time, 100, %X %x, st_mtime(&attrib.st_mtime));
	return time;
}

bool compare_time(char *time1, char *time2) {
	//compare the times here...
}

bool is_in_current_dir(char *targetname) {
	
	struct stat buf;
	return (stat(targetname, &buf) == 0);  
}

time_t get_url_time(char *url) {
	//curl -s -v --head http://foo.com/bar/baz.pdf 2>&1 | grep '^< Last-Modified:'

	int pid = fork();
	///DUNNO HOW TO DO THIS 
}

int url_exists(char *url) {

	CURL = *curl;
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

	return (isurl == CURLE_OK) ? 1 : 0;
}

bool startswith(char *url, char *dep) {

	//Arbitrary function for checking start of strings
	if(strncpm(url, dep, strlen(url) == 0)) {
		return 1;
	}

	return 0; 
}		

bool check_if_url(char * dependency) {

	//Check to see whether the dependency looks like a url
	const char *url1 = "file://";
	const char *url2 = "http://";
	const char *url3 = "https://";

	//If yes
	if(startswith(url1, dependency) || startswith(url2, dependency) || startswith(url3, dependency)) {
	
		return 1;

	}
	//If not a url
	return 0;

}

process_this_line(char *target, char **dependencies, char *action_line) {

	int something++ = 0;

	while(there are still dependencies to examine, ie **dependencies != '\0') {

		if(dependency is itself a target--check the data structure) {
				
			(somehow access data from the structure)
			
			char *newtarget = struct.target;
			char **newdependencies = struct.depenedencies;
			char *newaction_line = struct.action_line;
			process_this_line(newtarget, newdependencies, newaction_line);

		} else if(check_if_url(*dependencies)) {
			
			DO URL-y THINGS HERE;

		} else if(dependency is a file that can be found) {

			move to next dependency;

		} else if(dependency does not exist) {
				
			send some error;
		}
		something++;	

	}	

		
	if(target was modified more recently than all dependencies) {
			
		do nothing with this entire line--ie exit;
		
	} else {

		run action_line on SHELL;
	}	

}	

char ** isolate_dependencies(char *rest_of_line) {
	//split up all dependencies and return an array of char pointers
}

//If(no )


process_target_line(char *firstword, char *rest_of_line, int *no_variables, int *variable_length) {

	create structure filled with (MAYBE PUT THIS OUTSIDE OF THIS FUNCTION) 
	- target
	- array of dependencies
	- action line 


	//ALGORITHM FOR THIS FUNCTION

	char **dependencies = isolate_dependencies(&rest_of_line);

	process_this_line(target, dependencies, action_line);
	

	//Find current directory
	

	/*char *curr_dir = get_current_dir_name();
	//need to call free() after, when using "get_current_dir_name()"

	if(first_target_line) {
		char *default_target = firstword;
	}

	struct stat file
	if(stat(firstword, )) 
	

	//we need to chop off the ":"
	//then we need to get the next word
	//then we find the latest modification date of this word (possibly using stat())
	//compare this with the modification date of the *firstword
	//if *firstword is earlier, then 


	if(there are no dependencies) {
		rebuild the target
	}

	*/
}
