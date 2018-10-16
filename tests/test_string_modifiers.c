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


void test_movebacksimple(void) {

	char word1[] = "hello";
	char word2[] = "hello";
	char word3[] = "hello";
	
	//printf("1");
	move_back(word1, 1, 0);
	move_back(word2, 1, 1);
	move_back(word3, 1, 2);



	CU_ASSERT(0 == strcmp("hello", word1));
	CU_ASSERT(0 == strcmp("hllo", word2));
	CU_ASSERT(0 == strcmp("hlo", word3));
	


}

void test_movebackhard(void) {

	char word1[] = "hello";
	char word2[] = "hello";
	char word3[] = "hello";
	
	//printf("1");
	move_back(word1, -1, 0);


	CU_ASSERT(0 == strcmp("hello", word1));
	


}
void test_skipleadingspacesimple(void) {
	char word1[] = "   hello";
	char word2[] = "\thello";

	skip_leading_space(word1);
	skip_leading_space(word2);

	CU_ASSERT(0 == strcmp("hello", word1));
	CU_ASSERT(0 == strcmp("hello", word2));
}

void test_skipleadingspacehard(void) {
	char word1[] = "   hello";
	char word2[] = "\thello";

	skip_leading_space(word1);
	skip_leading_space(word2);

	CU_ASSERT(0 == strcmp("hello", word1));
	CU_ASSERT(0 == strcmp("hello", word2));
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
	if ((NULL == CU_add_test(pSuite1, "test move back simple", test_movebacksimple)) || (NULL == CU_add_test(pSuite1, "test skip leading space simple", test_skipleadingspacesimple)) || (NULL == CU_add_test(pSuite1, "test move back hard", test_movebackhard)) ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry
	return CU_get_error();

}
