#include "bake.h"

void process_bakefile(FILE *fp) {
    while(!feof(fp)) {
        char *line = nextline(fp);  // HANDLES CONTINUATION LINES

        if(line) {
            printf("%8s()\t%s\n", __func__, line);
            free(line);
        }
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