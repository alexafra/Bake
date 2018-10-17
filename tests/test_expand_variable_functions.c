// char * expand_variables (char * line, int * no_variables, char ** var_name_list, char ** var_value_list, int* error) {
// char * get_var_value(char * var_name, char ** var_name_list, char ** var_value_list, int no_vars) {


// char * get_var_name(char * line, int var_start, int var_name_length) {
// int get_var_length (char * line, int var_start, int length) {
#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

// #1. dollar sign is invisible
// #2. $ () means $is invisible and carry on
// #3. $( ) any space inside becomes an unrecognisable variable
// #4. $( this is undefined and throws an error.
// #5 $a is not acceptable
// #6 other braces are not acceptable
// #7 no nesting

void test_getvarnamesimple(void) {

}

void test_getvarnamehard(void) {

}


/*
Lone $ is not read


*/
