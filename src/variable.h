//why do i need the if statements

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

#define STRUCT_H ((Variable) {/* Null initializer */})

#endif /* STRUCT_H */
