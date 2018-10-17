#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

void test_movebacksimple(void) {

	char word1[] = "hello";
	char word2[] = "hello";
	char word3[] = "hello";
	
	int error1;
	int error2;
	int error3;
	//printf("1");
	move_back(word1, 1, 0, &error1);
	move_back(word2, 1, 1, &error2);
	move_back(word3, 1, 2, &error3);

	CU_ASSERT(0 == strcmp("hello", word1));
	CU_ASSERT(0 == strcmp("hllo", word2));
	CU_ASSERT(0 == strcmp("hlo", word3));
	
	CU_ASSERT(0 == error1);
	CU_ASSERT(0 == error2);
	CU_ASSERT(0 == error3);


}


void test_skipleadingspacesimple(void) {
	char line1[] = "   hello";
	char line2[] = "\thello";
	char line3[] = "   hello my name is ben";
	char line4[] = "\thello my name is josh";

	skip_leading_space(line1);
	skip_leading_space(line2);
	skip_leading_space(line3);
	skip_leading_space(line4);

	CU_ASSERT(0 == strcmp("hello", line1));
	CU_ASSERT(0 == strcmp("hello", line2));
	CU_ASSERT(0 == strcmp("hello my name is ben", line3));
	CU_ASSERT(0 == strcmp("hello my name is josh", line4));
}


void test_getfirstwordsimple (void) {
	char line1[] = "hello my name is alex";
	char line2[] = "  hello my name is alex";
	char line3[] = "\t hello my name is alex";

	char * firstword1 = getfirstword(line1);
	char * firstword2 = getfirstword(line2);
	char * firstword3 = getfirstword(line3);


	CU_ASSERT(0 == strcmp("hello", firstword1));
	CU_ASSERT(0 == strcmp("hello", firstword2));
	CU_ASSERT(0 == strcmp("hello", firstword3));

	free (firstword1);
	free (firstword2);
	free (firstword3);

}
