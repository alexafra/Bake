//#include "/Users/alexanderfrazis/Cits/Cits2002/Bake/src/bake.h"
#include "../src/bake.h"
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


void test_moveback(void) {
	printf("1");
	char * word0 = "hello";
	char * word1 = "hel123lo";
	printf("2");
	
	move_back(word1, 3, 3, 9);
	printf("3");


	CU_ASSERT(0 == strcmp(word0, word1));
	printf("4");


}

void test_skipleadingspace(void) {
	char * word0 = "hello";
	char * word1 = "   hello";
	//char * word2 = "hello   ";

	skip_leading_space(word1);

	CU_ASSERT(0 == strcmp(word0, word1));
	//CU_ASSERT(0 == strcmp(word0, word2));
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
	if ((NULL == CU_add_test(pSuite1, "test move_back", test_moveback)) || (NULL == CU_add_test(pSuite1, "test skip_leading_space", test_skipleadingspace))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry
	return CU_get_error();

}
