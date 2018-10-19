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

void test_numberlengthsimple (void) {
	int num1 = 10000;
	int num2 = 00001;
	int num3 = 0;
	int num4 = 6;
	int num5 = 10;
	int num6 = 77;
	int num7 = 749;
	int num8 = 8432;
	int num9 = 1000000000;

	int length1 = numberlength(num1);
	int length2 = numberlength(num2);
	int length3 = numberlength(num3);
	int length4 = numberlength(num4);
	int length5 = numberlength(num5);
	int length6 = numberlength(num6);
	int length7 = numberlength(num7);
	int length8 = numberlength(num8);
	int length9 = numberlength(num9);

	CU_ASSERT(5 == length1);
	CU_ASSERT(1 == length2);
	CU_ASSERT(1 == length3);
	CU_ASSERT(1 == length4);
	CU_ASSERT(2 == length5);
	CU_ASSERT(2 == length6);
	CU_ASSERT(3 == length7);
	CU_ASSERT(4 == length8);
	CU_ASSERT(10 == length9);



}

void test_itoasimple(void) {

	int num0 = 12;
	int num1 = 10000;
	int num2 = 00001;
	int num3 = 0;
	int num4 = 6;
	int num5 = 10;
	int num6 = 77;
	int num7 = 749;
	int num8 = 8432;
	int num9 = 1000000000;

	char* stnum0 = itoa(num0);
	char* stnum1 = itoa(num1);
	char* stnum2 = itoa(num2);
	char* stnum3 = itoa(num3);
	char* stnum4 = itoa(num4);
	char* stnum5 = itoa(num5);
	char* stnum6 = itoa(num6);
	char* stnum7 = itoa(num7);
	char* stnum8 = itoa(num8);
	char* stnum9 = itoa(num9);


	CU_ASSERT (0 == strcmp(stnum0, "12"));
	CU_ASSERT (0 == strcmp(stnum1, "10000"));
	CU_ASSERT (0 == strcmp(stnum2, "1"));
	CU_ASSERT (0 == strcmp(stnum3, "0"));
	CU_ASSERT (0 == strcmp(stnum4, "6"));
	CU_ASSERT (0 == strcmp(stnum5, "10"));
	CU_ASSERT (0 == strcmp(stnum6, "77"));
	CU_ASSERT (0 == strcmp(stnum7, "749"));
	CU_ASSERT (0 == strcmp(stnum8, "8432"));
	CU_ASSERT (0 == strcmp(stnum9, "1000000000"));

	free(stnum1);
	free(stnum2);
	free(stnum3);
	free(stnum4);
	free(stnum5);
	free(stnum6);
	free(stnum7);
	free(stnum8);
	free(stnum9);


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
	char line4[] = "hello";
	char line5[] = "      hello";
	char line6[] = "hello      ";
	char line7[] = "      hello       ";
	char line8[] = "";
	char line9[] = "\t";
	char line10[] = "    ";
	char line11[] = "  \t ";
	//other characters? - i dont think so

	char * firstword1 = getfirstword(line1);
	char * firstword2 = getfirstword(line2);
	char * firstword3 = getfirstword(line3);
	char * firstword4 = getfirstword(line4);
	char * firstword5 = getfirstword(line5);
	char * firstword6 = getfirstword(line6);
	char * firstword7 = getfirstword(line7);
	char * firstword8 = getfirstword(line8);
	char * firstword9 = getfirstword(line9);
	char * firstword10 = getfirstword(line10);
	char * firstword11 = getfirstword(line11);

	CU_ASSERT(0 == strcmp("hello", firstword1));
	CU_ASSERT(0 == strcmp("hello", firstword2));
	CU_ASSERT(0 == strcmp("hello", firstword3));
	CU_ASSERT(0 == strcmp("hello", firstword4));
	CU_ASSERT(0 == strcmp("hello", firstword5));
	CU_ASSERT(0 == strcmp("hello", firstword6));
	CU_ASSERT(0 == strcmp("hello", firstword7));
	CU_ASSERT(0 == strcmp("", firstword8));
	CU_ASSERT(0 == strcmp("", firstword9));
	CU_ASSERT(0 == strcmp("", firstword10));
	CU_ASSERT(0 == strcmp("", firstword11));

	free (firstword1);
	free (firstword2);
	free (firstword3);
	free (firstword4);
	free (firstword5);
	free (firstword6);
	free (firstword7);
	free (firstword8);
	free (firstword9);
	free (firstword10);
	free (firstword11);

}

