/*
	1. check memory issue
	2. check unit tests/

*/




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


/*
	Lord how do we test this shit
	We are going to test lines in our makefile first
	and then we are going to test some fuckery corner cases
	and then were going to the proff and show him what it does and does not pass

	C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror
TESTLOC = ../tests
TARGET = ../target

TESTTARGET = ../testtarget

test_expand_variable_functions.c

*/

void test_getspecialvarsimple (void) {
	//1 - 4 will produce values, 5-10 will produce "";
	char * var1 = "PID";
	char * var2 = "PPID";
	char * var3 = "PWD";
	char * var4 = "RAND";

	char * value1 = get_special_value(var1);
	char * value2 = get_special_value(var2);
	char * value3 = get_special_value(var3);
	char * value4 = get_special_value(var4);

	

	//prove there are contents
	CU_ASSERT(0 != strcmp(value1, ""));
	CU_ASSERT(0 != strcmp(value2, ""));
	CU_ASSERT(0 != strcmp(value3, ""));
	CU_ASSERT(0 != strcmp(value4, ""));

	//proving contents are correct
	int spval1 = atoi(value1);
	int spval2 = atoi(value2);
	char * spval3 = calloc(BUFSIZ, sizeof(char));
	spval3 = getcwd(spval3, BUFSIZ);


	CU_ASSERT(spval1 == getpid());
	CU_ASSERT(spval2 == getppid());
	CU_ASSERT(0 == strcmp(value3, spval3));
	

	//rand will fail because its producing randome values!!!!!
	//how do you test its producing random values????
	// int spval4 = atoi(value4);
	// CU_ASSERT(spval4 == rand());


	//proving non keywords fail
	char * var5 = " PID";
	char * var6 = " PID ";
	char * var7 = " RAND";
	char * var8 = " RAND ";
	char * var9 = "\tPPID";
	char * var10 = ".PWD";
	char * var11 = "PWDs";
	char * var12 = "var1";

	char * value5 = get_special_value(var5);
	char * value6 = get_special_value(var6);
	char * value7 = get_special_value(var7);
	char * value8 = get_special_value(var8);
	char * value9 = get_special_value(var9);
	char * value10 = get_special_value(var10);
	char * value11 = get_special_value(var11);
	char * value12 = get_special_value(var12);

	CU_ASSERT(value5 == NULL);
	CU_ASSERT(value6 == NULL);
	CU_ASSERT(value7 == NULL);
	CU_ASSERT(value8 == NULL);
	CU_ASSERT(value9 == NULL);
	CU_ASSERT(value10 == NULL);
	CU_ASSERT(value11 == NULL);
	CU_ASSERT(value12 == NULL);


	//something is being freed that shouldnt be
	free(value1);
	free(value2);
	free(value3);
	free(value4);

}

void test_getvarvaluesimple (void) {
	
	// //Youve declared an array of Variable pointers.
	// //But you havent allocated any memory adjacent to these pointers.
	// //thus this does closely may an array of Variables.

		Variable * variables[5];
    Variable variable1 = {"C99", "cc -std=c99"};
    Variable variable2 = {"CFLAGS", "-Wall -pedantic -Werror"};
    Variable variable3 = {"TESTLOC", "../tests"};
    Variable variable4 = {"TARGET", "../target"};

    variables[0] = &variable1;
    variables[1] = &variable2;
    variables[2] = &variable3;
    variables[3] = &variable4;
    variables[4] = NULL;

  
    //set variables values
    char *name1 = "C99";
    char *name2 = "CFLAGS";
    char *name3 = "TESTLOC";
    char *name4 = "TARGET";

    char *value1 = get_var_value(name1, variables);
    char *value2 = get_var_value(name2, variables);
    char *value3 = get_var_value(name3, variables);
    char *value4 = get_var_value(name4, variables);

    CU_ASSERT(0 == strcmp(value1, "cc -std=c99"));
    CU_ASSERT(0 == strcmp(value2, "-Wall -pedantic -Werror"));
    CU_ASSERT(0 == strcmp(value3, "../tests"));
    CU_ASSERT(0 == strcmp(value4, "../target"));



 //    //////////////////////////////////////////////////////
 //    //environment values
    char *envname1 = "SHELL";
    char *envname2 = "HOME";
    char *envname3 = "PWD";
    char *envname4 = "LOGNAME";
    char *envname5 = " PWD";
    char *envname6 = "PWD ";
    char *envname7 = "\tPWD";


    char *envvalue1 = get_var_value(envname1, variables);
    char *envvalue2 = get_var_value(envname2, variables);
    char *envvalue3 = get_var_value(envname3, variables);
    char *envvalue4 = get_var_value(envname4, variables);
    char *envvalue5 = get_var_value(envname5, variables);
    char *envvalue6 = get_var_value(envname6, variables);
    char *envvalue7 = get_var_value(envname7, variables);

    CU_ASSERT(0 == strcmp(envvalue1, "/bin/bash"));
    CU_ASSERT(0 == strcmp(envvalue2, "/home/kieren"));
    CU_ASSERT(0 == strcmp(envvalue3, "/home/kieren/Bake/src"));
    CU_ASSERT(0 == strcmp(envvalue4, "kieren"));
    CU_ASSERT(0 == strcmp(envvalue5, "\0"));
    CU_ASSERT(0 == strcmp(envvalue6, "\0"));
    CU_ASSERT(0 == strcmp(envvalue7, ""));


 //    ///////////////////////////////////////////////////////
 //    //special values


 	char * var21 = "PID";
	char * var22 = "PPID";
	char * var23 = "PWD";
	char * var24 = "RAND";

	char * value21 = get_var_value(var21, variables);
	char * value22 = get_var_value(var22, variables);
	char * value23 = get_var_value(var23, variables);
	char * value24 = get_var_value(var24, variables);

	

	//prove there are contents
	CU_ASSERT(0 != strcmp(value21, ""));
	CU_ASSERT(0 != strcmp(value22, ""));
	CU_ASSERT(0 != strcmp(value23, ""));
	CU_ASSERT(0 != strcmp(value24, ""));
 
	//proving contents are correct
	int spval21 = atoi(value21);
	int spval22 = atoi(value22);
	char * spval23 = calloc(BUFSIZ, sizeof(char));
	spval23 = getcwd(spval23, BUFSIZ);


	CU_ASSERT(spval21 == getpid());
	CU_ASSERT(spval22 == getppid());
	CU_ASSERT(0 == strcmp(value23, spval23));


	// //proving non keywords fail
	char * var25 = " PID";
	char * var26 = " PID ";
	char * var27 = " RAND";
	char * var28 = " RAND ";
	char * var29 = "\tPPID";
	char * var210 = ".PWD";
	char * var211 = "PWDs";
	char * var212 = "var1";

	char * value25 = get_var_value(var25, variables);
	char * value26 = get_var_value(var26, variables);
	char * value27 = get_var_value(var27, variables);
	char * value28 = get_var_value(var28, variables);
	char * value29 = get_var_value(var29, variables);
	char * value210 = get_var_value(var210, variables);
	char * value211 = get_var_value(var211, variables);
	char * value212 = get_var_value(var212, variables);

	CU_ASSERT(0 == strcmp(value25, ""));
	CU_ASSERT(0 == strcmp(value26, ""));
	CU_ASSERT(0 == strcmp(value27, ""));
	CU_ASSERT(0 == strcmp(value28, ""));
	CU_ASSERT(0 == strcmp(value29, ""));
	CU_ASSERT(0 == strcmp(value210, ""));
	CU_ASSERT(0 == strcmp(value211, ""));
	CU_ASSERT(0 == strcmp(value212, ""));



}

void test_substitutevariablesimple (void) {

	Variable *variables[6];

	Variable variable1 = {"C99", "cc -std=c99"};
    Variable variable2 = {"CFLAGS", "-Wall -pedantic -Werror"};
    Variable variable3 = {"TESTLOC", "../tests"};
    Variable variable4 = {"TARGET", "../target"};
    Variable variable5 = {"TESTTARGET", "../testtarget"};

    variables[0] = &variable1;
    variables[1] = &variable2;
    variables[2] = &variable3;
    variables[3] = &variable4;
    variables[4] = &variable5;
    variables[5] = NULL;



    int pos1 = 7;
    char * ln1 = "bake : $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o";

    char * ln1expanded = substitute_variable (pos1, ln1, variables);

    char * ln2expected = "bake : ../target/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o";

    CU_ASSERT(0 == strcmp(ln1expanded, ln2expected));


    // todo
    // char * line1 =
    // char * line2 = 

}

void test_expandvariablessimple (void) {
	Variable *variables[6];

	Variable variable1 = {"C99", "cc -std=c99"};
    Variable variable2 = {"CFLAGS", "-Wall -pedantic -Werror"};
    Variable variable3 = {"TESTLOC", "../tests"};
    Variable variable4 = {"TARGET", "../target"};
    Variable variable5 = {"TESTTARGET", "../testtarget"};

    variables[0] = &variable1;
    variables[1] = &variable2;
    variables[2] = &variable3;
    variables[3] = &variable4;
    variables[4] = &variable5;
    variables[5] = NULL;


    char * ln1 = "bake : $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o";
    int err1 = 0;
    char * ln1expanded = expand_variables (ln1, variables, &err1);

    char * ln1expected = "bake : ../target/bake.o ../target/process_bakefile.o ../target/expand_variables.o ../target/nextline.o ../target/string_modifiers.o ../target/process_variable_definition.o ../target/process_target_definition.o";

    CU_ASSERT(0 == strcmp(ln1expanded, ln1expected));


    char *ln2 = "$(C99) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c";
    char *ln2expanded = expand_variables(ln2, variables, &err1);
    char *ln2expected = "cc -std=c99 -Wall -pedantic -Werror -c -o ../target/bake.o bake.c";

    CU_ASSERT(0 == strcmp(ln2expanded, ln2expected));

    char *ln3 = "$(C9 9) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c";
    char *ln3expanded = expand_variables(ln3, variables, &err1);
    char *ln3expected = " -Wall -pedantic -Werror -c -o ../target/bake.o bake.c";

    CU_ASSERT(0 == strcmp(ln3expanded, ln3expected)); 

    char *ln4 = "$(C99) $(HOME) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c";
    char *ln4expanded = expand_variables(ln4, variables, &err1);
    char *ln4expected = "cc -std=c99 /home/kieren -Wall -pedantic -Werror -c -o ../target/bake.o bake.c";

    CU_ASSERT(0 == strcmp(ln4expanded, ln4expected));

	char *ln5 = "$(C99";
    char *ln5expanded = expand_variables(ln5, variables, &err1);
    char *ln5expected = NULL;

    CU_ASSERT(0 == strcmp(ln5expanded, ln5expected));


//     $(TARGET)/bake.o : bake.c bake.h
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c

// $(TARGET)/process_bakefile.o : process_bakefile.c bake.h
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/process_bakefile.o process_bakefile.c

// $(TARGET)/nextline.o : nextline.c bake.h
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/nextline.o nextline.c

// $(TARGET)/string_modifiers.o : string_modifiers.c bake.h
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/string_modifiers.o string_modifiers.c

// $(TARGET)/expand_variables.o : expand_variables.c bake.h
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/expand_variables.o expand_variables.c

// $(TARGET)/process_variable_definition.o : process_variable_definition.c bake.h 
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/process_variable_definition.o process_variable_definition.c 

// $(TARGET)/process_target_definition.o : process_target_definition.c bake.h 
// 	$(C99) $(CFLAGS) -c -o $(TARGET)/process_target_definition.o process_target_definition.c 
}



/*

char * expand_variables (char * line, Variable ** variable, int * error) {

	int length = strlen(line);
	char * subs_line = line;
	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
		
		if (subs_line[i] == '$') {
			subs_line = substitute_variable (i, line, variable, error);
			length = strlen(subs_line);
			i = 0;
		}
	}
	return line;
}

*/



/*
Lone $ is not read


*/
