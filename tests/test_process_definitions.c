#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

void test_numstrings (void) {
	char string1[] = "i like to ";
	char string2[] = "would like to\t";
	char string3[] = "what";

	char **stringlist1 = calloc(4, sizeof(char*));
	*(stringlist1 + 0) = string1;
	*(stringlist1 + 1) = string2;
	*(stringlist1 + 2) = string3;
	*(stringlist1 + 3) = NULL;

	int numstrings1 = numstrings(stringlist1);

	CU_ASSERT(numstrings1 == 3);
}

void test_separateline (void) {
	char line1[] = "hello my name is alex";
	char **wordlist1 = separate_line(line1);

	CU_ASSERT(0 == strcmp("hello", wordlist1[0]));
	CU_ASSERT(0 == strcmp("my", wordlist1[1]));
	CU_ASSERT(0 == strcmp("name", wordlist1[2]));
	CU_ASSERT(0 == strcmp("is", wordlist1[3]));
	CU_ASSERT(0 == strcmp("alex", wordlist1[4]));
	CU_ASSERT(wordlist1[5] == NULL);
}

void test_processtargetdefinition (void) {

	targets = (Target **) calloc (1, sizeof(Target*));
	*targets = NULL;


	char line1[] = "../target/nextline.o : nextline.c bake.h";
	char line2[] = "/expand_variables.o : expand_variables.c bake.h";
	char line3[] = "TARGET = ../target";
	char line4[] = "CFLAGS = -Wall -pedantic -Werror";
	char line5[] = "../target/bakeD.o : bake.c bake.h";


	char *first1 = getfirstword(line1);
	char *first2 = getfirstword(line2);
	char *first3 = getfirstword(line3);
	char *first4 = getfirstword(line4);
	char *first5 = getfirstword(line5);

	char *rest1 = get_rest_of_line(line1);
	char *rest2 = get_rest_of_line(line2);
	char *rest3 = get_rest_of_line(line3);
	char *rest4 = get_rest_of_line(line4);
	char *rest5 = get_rest_of_line(line5);

	process_target_definition(first1, rest1);
	process_target_definition(first2, rest2);
	process_target_definition(first3, rest3);
	process_target_definition(first4, rest4);
	process_target_definition(first5, rest5);


	CU_ASSERT(0 == strcmp("../target/nextline.o", targets[0]->target));
	CU_ASSERT(0 == strcmp("/expand_variables.o", targets[1]->target));
	CU_ASSERT(0 == strcmp("TARGET", targets[2]->target));
	CU_ASSERT(0 == strcmp("CFLAGS", targets[3]->target));
	CU_ASSERT(0 == strcmp("../target/bakeD.o", targets[4]->target));

	

	CU_ASSERT(0 == strcmp(targets[0]->dependencies[0], "nextline.c"));
	CU_ASSERT(0 == strcmp(targets[0]->dependencies[1], "bake.h"));

	CU_ASSERT(0 == strcmp(targets[1]->dependencies[0], "expand_variables.c"));
	CU_ASSERT(0 == strcmp(targets[1]->dependencies[1], "bake.h"));

	CU_ASSERT(0 == strcmp(targets[2]->dependencies[0], "../target"));

	CU_ASSERT(0 == strcmp(targets[3]->dependencies[0], "-Wall"));
	CU_ASSERT(0 == strcmp(targets[3]->dependencies[1], "-pedantic"));
	CU_ASSERT(0 == strcmp(targets[3]->dependencies[2], "-Werror"));

	CU_ASSERT(0 == strcmp(targets[4]->dependencies[0], "bake.c"));
	CU_ASSERT(0 == strcmp(targets[4]->dependencies[1], "bake.h"));

	

	CU_ASSERT(NULL == *targets[0]->actions);
	CU_ASSERT(NULL == *targets[1]->actions);
	CU_ASSERT(NULL == *targets[2]->actions);
	CU_ASSERT(NULL == *targets[3]->actions);
	CU_ASSERT(NULL == *targets[4]->actions);


}

void test_processactiondefinition (void) {

	targets = (Target **) calloc (1, sizeof(Target*));
	*targets = NULL;


	char targetline1[] = "../target/bakeD.o : bake.c bake.h";

	char *first1 = getfirstword(targetline1);
	char *rest1 = get_rest_of_line(targetline1);

	process_target_definition(first1, rest1);

	CU_ASSERT(0 == strcmp("../target/bakeD.o", targets[0]->target));

	CU_ASSERT(0 == strcmp(targets[0]->dependencies[0], "bake.c"));
	CU_ASSERT(0 == strcmp(targets[0]->dependencies[1], "bake.h"));

	char actionline1[] = "cc -std=c99 -Wall -pedantic -Werror -g -c -o ../target/bakeD.o bake.c";
	char actionline2[] = "cc -std=c99 -Wall -pedantic -Werror -g -c -o ../target/globals.o globals.c ";

	process_action_definition(actionline1);
	process_action_definition(actionline2);

	

	CU_ASSERT(0 == strcmp(targets[0]->actions[0], "cc -std=c99 -Wall -pedantic -Werror -g -c -o ../target/bakeD.o bake.c"));
	CU_ASSERT(0 == strcmp(targets[0]->actions[1], "cc -std=c99 -Wall -pedantic -Werror -g -c -o ../target/globals.o globals.c "));



}

/*
../target/bakeD.o : bake.c bake.h
	cc -std=c99 -Wall -pedantic -Werror -g -c -o ../target/bakeD.o bake.c

*/


void test_processvariabledefinition (void) {
	//*variables = NULL;

	variables = (Variable **) calloc (1, sizeof(Variable*));
	*variables = NULL;

	char * name1 = calloc(10, sizeof(char));
	char * name2 = calloc(10, sizeof(char));
	char * name3 = calloc(10, sizeof(char));
	char * name4 = calloc(10, sizeof(char));

	strcpy(name1, "var1");
	strcpy(name2, "var2");
	strcpy(name3, "var3");
	strcpy(name4, "var4");

	char * value1 = calloc(10, sizeof(char));
	char * value2 = calloc(10, sizeof(char));
	char * value3 = calloc(10, sizeof(char));
	char * value4 = calloc(10, sizeof(char));

	strcpy(value1, "test1");
	strcpy(value2, "test2");
	strcpy(value3, "test3");
	strcpy(value4, "test4");

	process_variable_definition(name1, value1);
	process_variable_definition(name2, value2);
	process_variable_definition(name3, value3);
	process_variable_definition(name4, value4);


	CU_ASSERT(0 == strcmp(variables[0]->var_name, "var1"));
	CU_ASSERT(0 == strcmp(variables[1]->var_name, "var2"));
	CU_ASSERT(0 == strcmp(variables[2]->var_name, "var3"));
	CU_ASSERT(0 == strcmp(variables[3]->var_name, "var4"));

	CU_ASSERT(0 == strcmp(variables[0]->var_value, "test1"));
	CU_ASSERT(0 == strcmp(variables[1]->var_value, "test2"));
	CU_ASSERT(0 == strcmp(variables[2]->var_value, "test3"));
	CU_ASSERT(0 == strcmp(variables[3]->var_value, "test4"));


	process_variable_definition("var21", "test21");
	process_variable_definition("var22", "test22");
	process_variable_definition("var23", "test23");
	process_variable_definition("var24", "test24");


	CU_ASSERT(0 == strcmp(variables[4]->var_name, "var21"));
	CU_ASSERT(0 == strcmp(variables[5]->var_name, "var22"));
	CU_ASSERT(0 == strcmp(variables[6]->var_name, "var23"));
	CU_ASSERT(0 == strcmp(variables[7]->var_name, "var24"));

	CU_ASSERT(0 == strcmp(variables[4]->var_value, "test21"));
	CU_ASSERT(0 == strcmp(variables[5]->var_value, "test22"));
	CU_ASSERT(0 == strcmp(variables[6]->var_value, "test23"));
	CU_ASSERT(0 == strcmp(variables[7]->var_value, "test24"));


	free (variables);

}


