#include "bake.h"

modifyfile(File *fp1, File *fp2)
{
    while(!feof(fp1)) {
        char *line = nextline(fp1);  // HANDLES CONTINUATION LINES
        //if 


        if(line) {
            printf("%8s()\t%s\n", __func__, line);
            free(line);
        }
  
    }
}