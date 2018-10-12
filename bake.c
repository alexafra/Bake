#include "bake.h"

#if defined(__linux__)

#endif


int main(int argc, char *argv[])
{
    if(argc > 1) {
        FILE *fpRaw        = fopen(argv[1], "r");

        if(fpRaw == NULL) {
            perror(argv[1]);
            return 1;
        }
        
        FILE *fpFin = fopen("finished_bake.txt","w");

        if(fpFin == NULL)
        {
            //TODO
            //perror(argv["tempbake.txt"]);
            //perror tempbake file integer
            fclose(fpRaw);
            return 1;
        }
        
        modifyfile(fpRaw, fpFin);
         
        fclose(fpRaw);                     // WE OPENED IT, SO WE CLOSE IT
        fclose(fpFin);
    }

    return 0;
}
