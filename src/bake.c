#include "bake.h"

#if defined(__linux__)

#endif

void print_targets (void) {
    
    int i = 0;
    //Loop through target structure and print
    printf("Targets:\n\n");
    while (targets[i] != NULL) {
        printf("\tTarget:\n");
        printf("\t\t%s\n", targets[i]->target);
        int j = 0;
        printf("\tDependencies:\n");
        //Loop through the dependency structure and print
        while (targets[i]->dependencies[j] != NULL) {
            printf("\t\t%s\n", targets[i]->dependencies[j]);
            ++j;
        }
        //Loop through the action structure and print
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
    //While you haven't reached the end of targets
    while (targets[i] != NULL) {
        int j = 0;
        //Loop through all actions and print
        while (targets[i]->actions[j] != NULL) {
            printf("%s\n", targets[i]->actions[j]);
            ++j;
        }
        ++i;
    }
}


int main(int argc, char *argv[])
{   

    //Parse your command line arguments
    int option;
    char *directoryname = NULL;
    char *filename = NULL;


    bool i_flag = false;
    bool n_flag = false;
    bool p_flag = false;
    bool s_flag = false;


    while( (option = getopt(argc, argv, "C:f:inps")) != -1) {

        switch (option) {

            case 'C' :
                directoryname = optarg;

                if (chdir(directoryname) != 0) {
                   perror("Directory change failed"); 
                   exit(EXIT_FAILURE);
                }

                break;

            case 'f' :
                filename = optarg;

                break;

            case 'i' :
                i_flag = true;
                break;

            case 'n' :
                n_flag = true;
                break;

            case 'p' :
                p_flag = true;
                break;

            case 's' :
                s_flag = true;
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

    //Open the bakefile     
    FILE *fp;
    if (filename != NULL) {
        fp        = fopen(filename, "r");
        //Check for error in opening file
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

    //Create structure for holding targets, dependencies, and actions
    targets = (Target **) calloc (1, sizeof(Target*));
    *targets = NULL;

    internal_representation(fp);
    if (p_flag) {
        print_targets();
    }

    if (!p_flag) {
        process_bake(i_flag, n_flag, s_flag);
    }

    fclose(fp);
    return 0;
}



