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

//what to do if no critical line
//currently null - perhaps throw error?????????
void test_getcriticalcharsimple (void) {
	char line1[] = "hello my name is alex";
	char line2[] = "  hello what are you doing";
	char line3[] = "\t hello gotcha doing";
	char line4[] = "$(TARGET)/nextline.o : nextline.c bake.h";
	char line5[] = "/expand_variables.o : expand_variables.c bake.h";
	char line6[] = "TARGET = ../target";
	char line7[] = "CFLAGS = -Wall -pedantic -Werror";
	char line8[] = "9 = cc -std=c99";
	char line9[] = "9";
	char line10[] = "Abigsingleword";
	char line11[] = "Abigsingleword       ";
	char line12[] = "       Abigsingleword";

	char critical1 = getcriticalchar(line1);
	char critical2 = getcriticalchar(line2);
	char critical3 = getcriticalchar(line3);
	char critical4 = getcriticalchar(line4);
	char critical5 = getcriticalchar(line5);
	char critical6 = getcriticalchar(line6);
	char critical7 = getcriticalchar(line7);
	char critical8 = getcriticalchar(line8);
	char critical9 = getcriticalchar(line9);
	char critical10 = getcriticalchar(line10);
	char critical11 = getcriticalchar(line11);
	char critical12 = getcriticalchar(line12);

	CU_ASSERT(critical1 == 'm');
	CU_ASSERT(critical2 == 'w');
	CU_ASSERT(critical3 == 'g');
	CU_ASSERT(critical4 == ':');
	CU_ASSERT(critical5 == ':');
	CU_ASSERT(critical6 == '=');
	CU_ASSERT(critical7 == '=');
	CU_ASSERT(critical8 == '=');
	CU_ASSERT(critical9 == '\0');
	CU_ASSERT(critical10 == '\0');
	CU_ASSERT(critical11 == '\0');
	CU_ASSERT(critical12 == '\0');
}

//issue with error management
void test_insertstringsimple (void) {
	char* base1 = "hello";
	char* insert1 = "hello";

	int err10;
	int err11;
	int err12;
	int err13;
	int err14;
	int err15;
	int err16;
	int err17;
	int err18;
	int err19;
	
	
	char* result10 = insert_string (base1, insert1, 0, &err10);
	char* result11 = insert_string (base1, insert1, 1, &err11);
	char* result12 = insert_string (base1, insert1, 2, &err12);
	char* result13 = insert_string (base1, insert1, 3, &err13);
	char* result14 = insert_string (base1, insert1, 4, &err14);
	char* result15 = insert_string (base1, insert1, 5, &err15);
	//Should be null from here.
	printf("\nerror in test1\n");
	char* result16 = insert_string (base1, insert1, 6, &err16);
	printf("\nerror in test2\n");
	char* result17 = insert_string (base1, insert1, 7, &err17);
	char* result18 = insert_string (base1, insert1, -1, &err18);
	char* result19 = insert_string (base1, insert1, -2, &err19);
	


	
	CU_ASSERT(0 == strcmp("hellohello", result10));
	CU_ASSERT(0 == strcmp("hhelloello", result11));
	CU_ASSERT(0 == strcmp("hehellollo", result12));
	CU_ASSERT(0 == strcmp("helhellolo", result13));
	CU_ASSERT(0 == strcmp("hellhelloo", result14));
	CU_ASSERT(0 == strcmp("hellohello", result15));
	CU_ASSERT(0 == strcmp("\0", result16));
	CU_ASSERT(0 == strcmp("\0", result17));
	CU_ASSERT(0 == strcmp("\0", result18));
	CU_ASSERT(0 == strcmp("\0", result19));

	

	CU_ASSERT(0 == err10);
	CU_ASSERT(0 == err11);
	CU_ASSERT(0 == err12);
	CU_ASSERT(0 == err13);
	CU_ASSERT(0 == err14);
	CU_ASSERT(0 == err15);

	CU_ASSERT(1 == err16);
	CU_ASSERT(1 == err17);
	CU_ASSERT(1 == err18);
	CU_ASSERT(1 == err19);

	free(result10);
	free(result11);
	free(result12);
	free(result13);
	free(result14);
	free(result15);
	free(result16);
	free(result17);
	free(result18);
	free(result19);


	
}


void test_substringsimple (void) {
					//"0123456789012345678"
	char* line1 = 	"this is a sentence"; //length is 18

	int err1;
	int err2;
	int err3;
	int err4;
	int err5;
	int err6;
	int err7;
	int err8;
	int err9;
	int err10;
	int err11;
	int err12;
	int err13;
	int err14;
	int err15;
	int err16;
	int err17;
	int err18;
	int err19;
	int err20;

	int err21;
	int err22;
	int err23;
	int err24;
	int err25;
	int err26;
	int err27;
	int err28;
	int err29;

	int err30;
	int err31;
	int err32;
	int err33;
	int err34;
	int err35;
	int err36;
	int err37;
	int err38;
	int err39;

	int err40;
	int err41;
	int err42;
	int err43;
	int err44;
	int err45;
	int err46;
	int err47;
	int err48;
	int err49;

	int err50;
	int err51;
	int err52;
	int err53;
	int err54;
	int err55;
	int err56;
	int err57;
	int err58;
	int err59;

	int err60;
	int err61;
	int err62;
	int err63;
	int err64;
	int err65;
	int err66;
	int err67;
	int err68;


	char* sub001 = substring(line1, 0, -1, &err1);
	char* sub002 = substring(line1, 5, -1, &err2);
	char* sub003 = substring(line1, 16, -1, &err3);
	char* sub004 = substring(line1, 17, -1, &err4);
	char* sub005 = substring(line1, 18, -1, &err5);
	char* sub006 = substring(line1, 19, -1, &err6);
	char* sub007 = substring(line1, 20, -1, &err7);

	char* sub008 = substring(line1, -2, -2, &err8);
	char* sub009 = substring(line1, -2, 0, &err9);
	char* sub010 = substring(line1, -2, 5, &err10);
	char* sub011 = substring(line1, -2, 20, &err11);

	char* sub012 = substring(line1, -1, -1, &err12);
	char* sub013 = substring(line1, -1, 0, &err13);
	char* sub014 = substring(line1, -1, 5, &err14);
	char* sub015 = substring(line1, -1, 20, &err15);

	char* sub016 = substring(line1, 0, 19, &err16);
	char* sub017 = substring(line1, 0, 20, &err17);
	char* sub018 = substring(line1, 0, 21, &err18);

	char* sub019 = substring(line1, 5, 0, &err19);
	char* sub020 = substring(line1, 5, 19, &err20);
	char* sub021 = substring(line1, 5, 20, &err21);
	char* sub022 = substring(line1, 5, 21, &err22);

	char* sub023 = substring(line1, 16, 6, &err23);
	char* sub024 = substring(line1, 16, 7, &err24);

	char* sub025 = substring(line1, 16, 19, &err25);
	char* sub026 = substring(line1, 16, 20, &err26);
	char* sub027 = substring(line1, 16, 21, &err27);

	char* sub028 = substring(line1, 17, 6, &err28);

	char* sub029 = substring(line1, 17, 19, &err29);
	char* sub030 = substring(line1, 17, 20, &err30);
	char* sub031 = substring(line1, 17, 21, &err31);

	char* sub032 = substring(line1, 18, 6, &err32);
	char* sub033 = substring(line1, 18, 17, &err33);

	char* sub034 = substring(line1, 18, 19, &err34);
	char* sub035 = substring(line1, 18, 20, &err35);
	char* sub036 = substring(line1, 18, 21, &err36);

	char* sub037 = substring(line1, 19, 6, &err37);
	char* sub038 = substring(line1, 19, 17, &err38);
	char* sub039 = substring(line1, 19, 18, &err39);
	char* sub040 = substring(line1, 19, 19, &err40);
	char* sub041 = substring(line1, 19, 20, &err41);
	char* sub042 = substring(line1, 19, 21, &err42);


	char* sub043 = substring(line1, 20, 6, &err43);
	char* sub044 = substring(line1, 20, 17, &err44);
	char* sub045 = substring(line1, 20, 18, &err45);
	char* sub046 = substring(line1, 20, 19, &err46);
	char* sub047 = substring(line1, 20, 20, &err47);
	char* sub048 = substring(line1, 20, 21, &err48);


	char* sub049 = substring(line1, 0, 0, &err49);
	char* sub050 = substring(line1, 0, 1, &err50);
	char* sub051 = substring(line1, 0, 2, &err51);
	char* sub052 = substring(line1, 0, 3, &err52);
	char* sub053 = substring(line1, 0, 4, &err53);
	char* sub054 = substring(line1, 0, 5, &err54);
	char* sub055 = substring(line1, 0, 16, &err55);
	char* sub056 = substring(line1, 0, 17, &err56);
	char* sub057 = substring(line1, 0, 18, &err57);
	char* sub058 = substring(line1, 5, 5, &err58);
	char* sub059 = substring(line1, 5, 6, &err59);
	char* sub060 = substring(line1, 5, 7, &err60);
	char* sub061 = substring(line1, 5, 8, &err61);
	char* sub062 = substring(line1, 5, 17, &err62);
	char* sub063 = substring(line1, 5, 18, &err63);
	char* sub064 = substring(line1, 16, 17, &err64);
	char* sub065 = substring(line1, 16, 18, &err65);
	char* sub066 = substring(line1, 17, 17, &err66);
	char* sub067 = substring(line1, 17, 18, &err67);
	char* sub068 = substring(line1, 18, 18, &err68);

	CU_ASSERT(0 == strcmp("", sub049));
	CU_ASSERT(0 == strcmp("t", sub050));
	CU_ASSERT(0 == strcmp("th", sub051));
	CU_ASSERT(0 == strcmp("thi", sub052));
	CU_ASSERT(0 == strcmp("this", sub053));
	CU_ASSERT(0 == strcmp("this ", sub054));
	CU_ASSERT(0 == strcmp("this is a senten", sub055));
	CU_ASSERT(0 == strcmp("this is a sentenc", sub056));
	CU_ASSERT(0 == strcmp("this is a sentence", sub057));
	CU_ASSERT(0 == strcmp("", sub058));
	CU_ASSERT(0 == strcmp("i", sub059));
	CU_ASSERT(0 == strcmp("is", sub060));
	CU_ASSERT(0 == strcmp("is ", sub061));
	CU_ASSERT(0 == strcmp("is a sentenc", sub062));
	CU_ASSERT(0 == strcmp("is a sentence", sub063));
	CU_ASSERT(0 == strcmp("c", sub064));
	CU_ASSERT(0 == strcmp("ce", sub065));
	CU_ASSERT(0 == strcmp("", sub066));
	CU_ASSERT(0 == strcmp("e", sub067));
	CU_ASSERT(0 == strcmp("", sub068));


	CU_ASSERT(0 == strcmp("\0", sub001));
	CU_ASSERT(0 == strcmp("\0", sub002));
	CU_ASSERT(0 == strcmp("\0", sub003));
	CU_ASSERT(0 == strcmp("\0", sub004));
	CU_ASSERT(0 == strcmp("\0", sub005));
	CU_ASSERT(0 == strcmp("\0", sub006));
	CU_ASSERT(0 == strcmp("\0", sub007));
	CU_ASSERT(0 == strcmp("\0", sub008));
	CU_ASSERT(0 == strcmp("\0", sub009));
	CU_ASSERT(0 == strcmp("\0", sub010));
	CU_ASSERT(0 == strcmp("\0", sub011));
	CU_ASSERT(0 == strcmp("\0", sub012));
	CU_ASSERT(0 == strcmp("\0", sub013));
	CU_ASSERT(0 == strcmp("\0", sub014));
	CU_ASSERT(0 == strcmp("\0", sub015));
	CU_ASSERT(0 == strcmp("\0", sub016));
	CU_ASSERT(0 == strcmp("\0", sub017));
	CU_ASSERT(0 == strcmp("\0", sub018));
	CU_ASSERT(0 == strcmp("\0", sub019));
	CU_ASSERT(0 == strcmp("\0", sub020));
	CU_ASSERT(0 == strcmp("\0", sub021));
	CU_ASSERT(0 == strcmp("\0", sub022));
	CU_ASSERT(0 == strcmp("\0", sub023));
	CU_ASSERT(0 == strcmp("\0", sub024));
	CU_ASSERT(0 == strcmp("\0", sub025));
	CU_ASSERT(0 == strcmp("\0", sub026));
	CU_ASSERT(0 == strcmp("\0", sub027));
	CU_ASSERT(0 == strcmp("\0", sub028));
	CU_ASSERT(0 == strcmp("\0", sub029));
	CU_ASSERT(0 == strcmp("\0", sub030));
	CU_ASSERT(0 == strcmp("\0", sub031));
	CU_ASSERT(0 == strcmp("\0", sub032));
	CU_ASSERT(0 == strcmp("\0", sub033));
	CU_ASSERT(0 == strcmp("\0", sub034));
	CU_ASSERT(0 == strcmp("\0", sub035));
	CU_ASSERT(0 == strcmp("\0", sub036));
	CU_ASSERT(0 == strcmp("\0", sub037));
	CU_ASSERT(0 == strcmp("\0", sub038));
	CU_ASSERT(0 == strcmp("\0", sub039));
	CU_ASSERT(0 == strcmp("\0", sub040));
	CU_ASSERT(0 == strcmp("\0", sub041));
	CU_ASSERT(0 == strcmp("\0", sub042));
	CU_ASSERT(0 == strcmp("\0", sub043));
	CU_ASSERT(0 == strcmp("\0", sub044));
	CU_ASSERT(0 == strcmp("\0", sub045));
	CU_ASSERT(0 == strcmp("\0", sub046));
	CU_ASSERT(0 == strcmp("\0", sub047));
	CU_ASSERT(0 == strcmp("\0", sub048));

	CU_ASSERT(1 == err1);
	CU_ASSERT(1 == err2);
	CU_ASSERT(1 == err3);
	CU_ASSERT(1 == err4);
	CU_ASSERT(1 == err5);
	CU_ASSERT(1 == err6);
	CU_ASSERT(1 == err7);
	CU_ASSERT(1 == err8);
	CU_ASSERT(1 == err9);
	CU_ASSERT(1 == err10);
	CU_ASSERT(1 == err11);
	CU_ASSERT(1 == err12);
	CU_ASSERT(1 == err13);
	CU_ASSERT(1 == err14);
	CU_ASSERT(1 == err15);
	CU_ASSERT(1 == err16);
	CU_ASSERT(1 == err17);
	CU_ASSERT(1 == err18);
	CU_ASSERT(1 == err19);
	CU_ASSERT(1 == err20);
	CU_ASSERT(1 == err21);
	CU_ASSERT(1 == err22);
	CU_ASSERT(1 == err23);
	CU_ASSERT(1 == err24);
	CU_ASSERT(1 == err25);
	CU_ASSERT(1 == err26);
	CU_ASSERT(1 == err27);
	CU_ASSERT(1 == err28);
	CU_ASSERT(1 == err29);
	CU_ASSERT(1 == err30);
	CU_ASSERT(1 == err31);
	CU_ASSERT(1 == err32);
	CU_ASSERT(1 == err33);
	CU_ASSERT(1 == err34);
	CU_ASSERT(1 == err35);
	CU_ASSERT(1 == err36);
	CU_ASSERT(1 == err37);
	CU_ASSERT(1 == err38);
	CU_ASSERT(1 == err39);
	CU_ASSERT(1 == err40);
	CU_ASSERT(1 == err41);
	CU_ASSERT(1 == err42);
	CU_ASSERT(1 == err43);
	CU_ASSERT(1 == err44);
	CU_ASSERT(1 == err45);
	CU_ASSERT(1 == err46);
	CU_ASSERT(1 == err47);
	CU_ASSERT(1 == err48);

	CU_ASSERT(0 == err49);
	CU_ASSERT(0 == err50);
	CU_ASSERT(0 == err51);
	CU_ASSERT(0 == err52);
	CU_ASSERT(0 == err53);
	CU_ASSERT(0 == err54);
	CU_ASSERT(0 == err55);
	CU_ASSERT(0 == err56);
	CU_ASSERT(0 == err57);
	CU_ASSERT(0 == err58);
	CU_ASSERT(0 == err59);
	CU_ASSERT(0 == err60);
	CU_ASSERT(0 == err61);
	CU_ASSERT(0 == err62);
	CU_ASSERT(0 == err63);
	CU_ASSERT(0 == err64);
	CU_ASSERT(0 == err65);
	CU_ASSERT(0 == err66);
	CU_ASSERT(0 == err67);
	CU_ASSERT(0 == err68);



}


// extern void trimline (char *);


//////////////Incomplete ////////////////
void test_movebackhard(void) {
	char word1[] = "hello";
	int err1;

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

	//Add suite1 to registry
	pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);

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

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry
	return CU_get_error();

}
