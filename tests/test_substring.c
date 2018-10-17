#include "test.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

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
