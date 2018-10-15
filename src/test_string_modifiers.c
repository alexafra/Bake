//#include "/Users/alexanderfrazis/Cits/Cits2002/Bake/src/bake.h"
#include "bake.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
//gcc -Wall  test_string_modifiers.c  -lcunit -o test_string_modifiers

//-I$HOME/local/include
//-L$HOME/local/lib 

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}

void test_trimline(void) {
	char * word0 = "hello";
	char * word1 = "   hello";
	char * word2 = "hello   ";
	
	trimline(word1);
	trimline(word2);

	CU_ASSERT(0 == strcmp(word0, word1));
	CU_ASSERT(0 == strcmp(word0, word2));
}

int main (void) {

	//Initialize CUnit test registry
	CU_pSuite pSuite1 = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	//Add suite1 to registry
	pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);

	if (NULL == pSuite1) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Add test1 to suite1
	if ((NULL == CU_add_test(pSuite1, "\n\n....... Testing trimline function ........\n\n", test_trimline))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry
	return CU_get_error();

}
