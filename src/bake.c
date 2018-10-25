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

    //C and f will take another string
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

// //      -i : ignore the unsuccessful termination of actions; continue executing a target's actions even if any fail.
// // 
//         -n : print (to stdout) each shell-command-sequence before it is to be executed, but do not actually execute the commands. Assume that each shell-command-sequence executes successfully. This option enables bake to simply report what it would do, without doing it.
// //      
//         -p : after reading in the specification file, print its information (from bake's internal representation) to stdout with all variable expansions performed. Then simply exit with success. 
// // Only the targets, dependencies, and actions need be printed (though you may wish to also print the variables (names and values).
// //      -s : execute silently, do not print each shell-command-sequence before it is executed.

    

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
    
    //Process those targets, etc.
    process_bakefile(fp);
    
    process_bake();
    //Close the file at the end
    fclose(fp);

    return 0;
}



