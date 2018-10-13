#include "bake.h"

#if defined(__linux__)

#endif


int main(int argc, char *argv[])
{
    if(argc > 1) {
        FILE *fp        = fopen(argv[1], "r");

        if(fp == NULL) {
            perror(argv[1]);
            return 1;
        }
        
        process_bakefile(*fp)
                             // WE OPENED IT, SO WE CLOSE IT
        fclose(fp);
    }

    return 0;
}
