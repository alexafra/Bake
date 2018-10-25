/* CITS2002 Project 2018 
Names:              Alex Franzis,   Kieren Underwood
Student numbers:    21988858,       21315543 
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct Variable {
    char * var_name;
    char * var_value;
} Variable;


typedef struct Target {
	char * target;
	char ** dependencies;
	char ** actions;
} Target;

#endif /* STRUCT_H */
