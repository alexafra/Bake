#include "bake.h"

#if defined(__linux__)

#endif

void print_bakefile (void) {
    int i = 0;
    printf("Targets:\n\n");
    while (targets[i] != NULL) {
        printf("\tTarget:\n");
        printf("\t\t%s\n", targets[i]->target);
        int j = 0;
        printf("\tDependencies:\n");
        while (targets[i]->dependencies[j] != NULL) {
            printf("\t\t%s\n", targets[i]->dependencies[j]);
            ++j;
        }
        int k = 0;
        printf("\tActions:\n");
        while (targets[i]->actions[k] != NULL) {
            printf("\t\t%s\n", targets[i]->actions[k]);
            ++k;
        }
        ++i;
        printf("\n");
    }
}


int main(int argc, char *argv[])
{
    if(argc > 1) {
        //need to check access()
        FILE *fp        = fopen(argv[1], "r");

        if(fp == NULL) {
            perror(argv[1]);
            return 1;
        }

        targets = (Target **) calloc (1, sizeof(Target*));
        *targets = NULL;
        
        process_bakefile(fp);
//
        
                             // WE OPENED IT, SO WE CLOSE IT
        //print_bakefile();

        process_bake();
        fclose(fp);
    }

    return 0;
}



