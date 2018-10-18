//why do i need the if statements

#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct Variable {
    char * var_name;
    char * var_value;
} Variable;

#define VARIABLE_NULL ((Variable) {/* Null initializer */})

#endif /* VARIABLE_H */
