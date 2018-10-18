#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

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
	char* result16 = insert_string (base1, insert1, 6, &err16);
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
