#include "bake.h"

/*
where zero-or-more whitespace characters (spaces and tabs) may appear before and after the ':' character. The first targetname found in a file is the default target, 
and is the one to be rebuilt if no other targetname is provided on bake's command-line (see later).

If the targetname represents a file in the current working directory, then the file's modification date is used as the date of the target. 
Otherwise, the target is assumed to be created by the target's actions, if they are successfully executed.

Dependencies: Each target line may provide zero-or-more dependencies. If there are no dependencies, then the target requires rebuilding.
 There are three types of dependencies - ones that identify existing files on disk, ones that identify other targets, and ones that identify 
 a web-based URL (a Uniform Resource Locator). If any dependency does not exist, or has been modified more recently that its target, then the target requires rebuilding (see Action lines).


URL dependencies: if a dependency looks like an simple URL (it commences with the pattern file://, http://, or https://) it is assumed to define a URL
 to be requested to determine if the associated file exists and has been modified more recently that the current target.
bake must use the external utility curl to determine if the file (indicated by the URL) has been modified more recently than the current target. 
curl is usually installed on macOS or Linux machines, and is available from curl.haxx.se. Note that bake should not download the indicated file, 
just use curl's --head option to find the modification date. However, any target's action may choose to explicitly download a file
. It is an error if curl reports if a URL-based dependency is not found; it is not sought as a target. 

*/

//If(no )

process_target_line(char *firstword, char *rest_of_line, int *no_variables, int *variable_length) {

	//Find current directory
	char *curr_dir = get_current_dir_name();
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


}