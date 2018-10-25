#include "bake.h"

#if defined(__linux__)

#endif

void print_targets (void) {
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

void print_actions (void) {
    int i = 0;
    while (targets[i] != NULL) {
        int j = 0;
        while (targets[i]->actions[j] != NULL) {
            printf("%s\n", targets[i]->actions[j]);
            ++j;
        }
        ++i;
    }
}




int main(int argc, char *argv[])
{   

    int option;
    char *directoryname = NULL;
    char *filename = NULL;

    while( (option = getopt(argc, argv, "C:f:inps")) != -1) {

        switch (option) {

            case 'C' :
                directoryname = optarg;

                if (chdir(directoryname) != 0) {
                   printf("Directory change failed"); 
                   exit(EXIT_FAILURE);
                }

                break;

            case 'f' :
                filename = optarg;

                break;

            case 'i' :
                break;

            case 'n' :
                break;

            case 'p' :
                print_targets();
                break;

            case 's' :
                break;

            case '?' :
                if((optopt == 'C') | (optopt == 'f')) {
                    printf("Option -%c needs an argument\n", optopt);
                    exit(EXIT_FAILURE);

                } else {
                    printf("Unknown option -%c.\n", optopt);
                    exit(EXIT_FAILURE);
                }
                break;

            default :
                printf("getopt");                                              
        }
    }

    

    
    FILE *fp;
    if (filename != NULL) {
        fp        = fopen(filename, "r");

        if(fp == NULL) {
            perror(filename);
            return 1;
        }
    } else {
        filename = "Bakefile";
        fp        = fopen(filename, "r");
        if(fp == NULL) {
            filename = "bakefile";
            fp        = fopen(filename, "r");
            if(fp == NULL) {
                perror(filename);
                return 1;
            }
        }
    }
    


    targets = (Target **) calloc (1, sizeof(Target*));
    *targets = NULL;
    
    process_bakefile(fp);
    
    // WE OPENED IT, SO WE CLOSE IT
    //print_bakefile();

    process_bake();
    fclose(fp);

    return 0;
}



