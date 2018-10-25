#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

void test_targets (void) {

	char *url1 = "http://google.com";
	char *url2 = "https://google.com";
	char *url3 = "file://google.com";
	char *url4 = " http://google.com";
	char *url5 = "ht tp://something.com";
	char *url6 = "https:/something.com";
	char *url7 = "http:/google.com";


	int u1 = is_dependency_url(url1);
	int u2 = is_dependency_url(url2);
	int u3 = is_dependency_url(url3);
	int u4 = is_dependency_url(url4);
	int u5 = is_dependency_url(url5);
	int u6 = is_dependency_url(url6);
	int u7 = is_dependency_url(url7);


	CU_ASSERT(1 == u1);
	CU_ASSERT(1 == u2);
	CU_ASSERT(1 == u3);
	CU_ASSERT(1 != u4);
	CU_ASSERT(1 != u5);
	CU_ASSERT(1 != u6);
	CU_ASSERT(1 != u7);


	//DUNNO WHATS GOING ON WITH THESE TESTS. 

	char *file1 = "test1";
	char *file2 = "test2";
	char *file3 = "test3";
	char *file4 = "test4";
	char *file5 = "globals.c";
	char *file6 = "bake.c";
	char *file7 = "bake.h";

	bool f1 = is_target_older(file1, file2);
	bool f2 = is_target_older(file2, file3);
	bool f3 = is_target_older(file3, file4);
	// bool f4 = is_target_older(file4, file5);
	bool f5 = is_target_older(file5, file6);
	bool f6 = is_target_older(file6, file7);
	bool f7 = is_target_older(file7, file5);

	CU_ASSERT(f1 == true);
	CU_ASSERT(f2 != true);
	CU_ASSERT(f3 == true);
	// CU_ASSERT(f4 != true);
	CU_ASSERT(f5 == true);
	CU_ASSERT(f6 == true);
	CU_ASSERT(f7 != true);
	
	// char *file1 = "makefile";
	// char *file2 = "bake.c";
	// char *file3 = "globals.c";
	// // char *file4 = "nothing";
	// char *file5 = "../tests/test_substring.c";
	// char *file6 = "../tests/test_target_lines.c";
	// char *file7 = "nextline.c";

	// bool dep1 = is_dependency_file(file1);
	// bool dep2 = is_dependency_file(file2);
	// bool dep3 = is_dependency_file(file3);
	// // bool dep4 = is_dependency_file(file4);
	// bool dep5 = is_dependency_file(file5);
	// bool dep6 = is_dependency_file(file6);
	// bool dep7 = is_dependency_file(file7);

	// CU_ASSERT(dep1 == true);
	// CU_ASSERT(dep2 == true);
	// CU_ASSERT(dep3 == true);
	// // CU_ASSERT(dep4 != true);
	// CU_ASSERT(dep5 == true);
	// CU_ASSERT(dep6 == true);
	// CU_ASSERT(dep7 == true);

}
