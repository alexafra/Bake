#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <time.h>
#include <linux/limits.h>

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

// bool is_in_current_dir(char *targetname) {
	
// 	//THIS WORKS
// 	struct stat buf;
// 	return (stat(targetname, &buf) == 0);  
// }

// time_t get_url_time(char *url) {
// 	//curl -s -v --head http://foo.com/bar/baz.pdf 2>&1 | grep '^< Last-Modified:'
// 	FILE *header;
// 	char *filename = "time.txt";

// 	header = fopen("time.txt", "w");
// 	if (header == NULL) {
// 		printf("Failed to create file for storage\n");
// 		exit(EXIT_FAILURE);
// 	} else { 
// 	execl("curl -o ", filename, "-s -v --head ", url, "2>&1 | grep '^< Last-Modified:'", NULL);
// 	}

// 	char modification_date[100];
// 	fgets(modification_date, 100, header);

// 	printf("%s\n", modification_date);

// 	fclose(header);
// }

char * geturldetails(char * url ) {
	// FILE * header;
	// header = fopen("details.txt", "w");
	// char *filename = "details.txt";

	pid_t pid;
	pid = fork();
	if(pid == 0) {
		//Open a file to send header to
		FILE *header;
		char *filename = "time.txt";

		header = fopen("time.txt", "w");
		
		//Check if the file fails to open
		if (header == NULL) {
			printf("Failed to create file for storage\n");
			exit(EXIT_FAILURE);
		} else { 
		//run the curl operation	
		execl(getenv("SHELL"),"curl -o ", filename, "-s -v --head ", url, NULL);
		
		}
	fclose(header);
	}
			
		// //check the file to see where "< Last-Modified:" line is
		// while(!feof(header)) {

  //       	char *line = nextline(header);
  //       	char *dateline = "< Last-Modified:";
  //       	if(startswith(dateline, line)) {
        		
  //       		//Copy this line into another char
  //       		int err;
  //       		move_back(line, 0, strlen(dateline), &err);
  //       		if(err !=0) {
  //       			perror("Move back method failed");
  //       		} else {
  //       			return line;
  //       		}
  //       	} else{
  //       		free(line);
  //       	}
  //       }	

		
	} 
	

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

// bool startswith(char *url, char *dep) {

// 	//THIS WORKS
// 	//Arbitrary function for checking start of strings
// 	if(strncmp(url, dep, strlen(url)) == 0) {
// 		return true;
// 	} else {
// 		return false;	
// 	}
	 
// }		

// bool check_if_url(char *dependency) {
	
// 	//THIS WORKS
// 	//Check to see whether the dependency looks like a url
// 	char *url1 = "file://";
// 	char *url2 = "http://";
// 	char *url3 = "https://";

// 	//If yes
// 	if(startswith(url1, dependency) || startswith(url2, dependency) || startswith(url3, dependency)) {
	
// 		return true;

// 	} else {
// 	//If not a url
// 	return false;
// 	}
// }

// time_t get_modification_date(char *filename) {
	
// 	//THIS COMPILES BUT MAY NOT WORK... NOT TESTED
// 	time_t filetime;
// 	struct stat attrib;
// 	if(stat(filename, &attrib) != 0) {
// 		perror("Stat fail");
	
// 	} else {

// 	filetime = attrib.st_mtime;
// 	return filetime;
// 	}
// }

// bool is_more_recent(time_t time1, time_t time2) {
	
// 	//THIS HAS PROBLEMS WITH 'makes integer from pointer without a cast'

// 	//compare the times here...

// 	if(difftime(time1, time2) > 0) {
// 		return true;
// 	}
// 	return false;
// }


// time_t geturltime (char *url) {
	
// 	time_t timer;
// 	time(&timer);

// 	return timer;
// }

// bool is_older (time_t time1, time_t time2) {
	
// 	//Compare modification dates here

// 	if(difftime(time1, time2) < 0) {
// 		return true;
// 	}
// 	return false;
// }

int main(char argc, char *argv[]) {

	// get_url_time(argv[1]);
	// char *url = "anything";
	// time_t urltime = geturltime(url);

	// sleep(3);

	// char *url2 = "anything2";
	// time_t urltime2 = geturltime(url);

	// if(is_older(urltime, urltime2)) {
	// 	printf("worked\n");
	// } else {
	// 	printf("didn't work\n");
	// }
	geturldetails("http://teaching.csse.uwa.edu.au/units/CITS2002/project/dependency-5m");
	exit(EXIT_SUCCESS);

}

