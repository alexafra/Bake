//#include "/Users/alexanderfrazis/Cits/Cits2002/Bake/src/bake.h"
#include "test.h"
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


// extern void trimline (char *);


//////////////Incomplete ////////////////
void test_movebackhard(void) {
	char word1[] = "hello";
	int err1 = 0;

	move_back(word1, -1, 0, &err1);

	CU_ASSERT(0 == strcmp("\0", word1));

	CU_ASSERT(1 == err1)
}
void test_skipleadingspacehard(void) {
}

void test_insertstringhard (void) {
}

void test_getcriticalcharhard (void) {
}

void test_getfirstwordhard (void) {

}

void test_substringhard (void) {

}





int main (void) {

	//Initialize CUnit test registry
	CU_pSuite pSuite1 = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	//Suite 1
	pSuite1 = CU_add_suite("string modifiers testing", init_suite, clean_suite);

	if (NULL == pSuite1) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Add test1 to suite1
	if ((NULL == CU_add_test(pSuite1, "test move back simple", test_movebacksimple))
		|| (NULL == CU_add_test(pSuite1, "test skip leading space simple", test_skipleadingspacesimple)) 
		|| (NULL == CU_add_test(pSuite1, "test get first word simple", test_getfirstwordsimple))
		|| (NULL == CU_add_test(pSuite1, "test get critical char simple", test_getcriticalcharsimple))
		|| (NULL == CU_add_test(pSuite1, "test get insert string simple", test_insertstringsimple ))
		|| (NULL == CU_add_test(pSuite1, "test get substring simple", test_substringsimple ))
		|| (NULL == CU_add_test(pSuite1, "test itoa simple", test_itoasimple ))
		|| (NULL == CU_add_test(pSuite1, "test numberlength simple", test_numberlengthsimple ))
		
		

		|| (NULL == CU_add_test(pSuite1, "test skip leading space hard", test_skipleadingspacehard))
		|| (NULL == CU_add_test(pSuite1, "test move back hard", test_movebackhard))
		|| (NULL == CU_add_test(pSuite1, "test get first word hard", test_getfirstwordhard))
		|| (NULL == CU_add_test(pSuite1, "test get critical char hard", test_getcriticalcharhard))
		|| (NULL == CU_add_test(pSuite1, "test get insert string hard", test_insertstringhard ))
		|| (NULL == CU_add_test(pSuite1, "test get substring ahrd", test_substringhard ))
	) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Suite 2
	CU_pSuite pSuite2 = NULL;
	pSuite2 = CU_add_suite("expand variables testing", init_suite, clean_suite);

	if (NULL == pSuite2) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (	(NULL == CU_add_test(pSuite1, "test expandvariables simple", test_expandvariablessimple ))
		|| 	(NULL == CU_add_test(pSuite1, "test getspecialvar simple", test_getspecialvarsimple ))
		|| 	(NULL == CU_add_test(pSuite1, "test getvarvalue simple", test_getvarvaluesimple ))
	) { 
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry
	return CU_get_error();

}
