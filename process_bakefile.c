#include "bake.h"

void process_bakefile(FILE *fp) {
    bool just_processed_target = false;
    //Set environemnt and special cases into variable arrays.
    set_var_exp();

    while(!feof(fp)) {
        char *line = nextline(fp);  // HANDLES CONTINUATION LINES
        char * firstword;

        //The line is a comment line
        if(line[0] == '#') {
            free (line);
            continue;
        }
        if (is_all_space(line)) {
            free (line);
            continue;
        }

        //expand any varibales in the line

        //This line is a target
        if (line[0] == '\t' && just_processed_target == true) {

        }

        //Blanks space
        //
        //






        free (line);
    }
}


while not end of file
get the next full/continuation line
expand any variables on that line

categorise the expanded line:
  if it begins with '#', ignore this line and loop to read the next line

  if the line begins with a tab **and we've just processed a new target**, add this action to that target

  skip any leading spaces or tabs

  if we've reached the end of line, then the whole line was a blank line, so ignore it like a comment line

  now find the first 'word' on the line, collecting its characters until we find a space, tab, =, or :

  if we found '=', call   process_variable_definition(word, rest_of_line),  ideally in a different file

  if we found ':', call   process_target_definition(word, rest_of_line), ideally in a different file

  otherwise the line is unrecognised, print any error message and exit

fclose file