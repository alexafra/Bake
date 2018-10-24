#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

void test_checkifurl(void) {

	char *url1 = "http://google.com";
	char *url2 = "https://google.com";
	char *url3 = "file://google.com";
	char *url4 = " http://google.com";

	int u1 = check_if_url(url1);
	int u2 = check_if_url(url2);
	int u3 = check_if_url(url3);
	int u4 = check_if_url(url4);

	CU_ASSERT(1 == u1);
	CU_ASSERT(1 == u2);
	CU_ASSERT(1 == u3);
	CU_ASSERT(1 == u4);
}