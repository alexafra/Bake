#include "bake.h"
//  READ SUCCESSIVE LINES UNTIL END-OF-FILE OR ONE DOES NOT END WITH '\'
//returns null at eof?
char *nextline(FILE *fp)
{
    char        *fullline       = NULL;
    int         fulllength      = 0;

    char        thisline[BUFSIZ];
    int         thislength      = 0;

    while(fgets(thisline, sizeof thisline, fp) != NULL) {
        trimline(thisline);                     // REMOVE TRAILING \n or \r
        thislength      = strlen(thisline);
        fulllength      += thislength;

        printf("%8s()\t%s\n", __func__, thisline); //the 8 refers to how many characters, minimum, it should have (and it pads it otherwise)... the \t is a "tab"

        if(fullline == NULL) {
            fullline    = strdup(thisline);
        }
        else {
            fullline     = realloc(fullline, fulllength+1);
            strcat(fullline, thisline);
        }
//  SHOULD WE CONTINUE READING, OR IS THE LINE COMPLETE?
        if(fullline[ fulllength-1 ] != CH_CONTINUATION) {
            break;
        }
        fullline[ --fulllength ] = '\0';        // REMOVE TRAILING '\'
    }
    return fullline;
}
