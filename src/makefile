C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror
TESTLOC = ../tests
TARGET = FUCK
TARGET = ../target

TESTTARGET = ../testtarget


###################test########################



################Compound Targets#######################

bake : $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o
	$(C99) $(CFLAGS) -o bake $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o



##################Base Targets#########################

$(TARGET)/bake.o : bake.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c

$(TARGET)/process_bakefile.o : process_bakefile.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/process_bakefile.o process_bakefile.c

$(TARGET)/nextline.o : nextline.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/nextline.o nextline.c

$(TARGET)/string_modifiers.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/string_modifiers.o string_modifiers.c

$(TARGET)/expand_variables.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/expand_variables.o expand_variables.c

$(TARGET)/process_variable_definition.o : process_variable_definition.c bake.h 
	$(C99) $(CFLAGS) -c -o $(TARGET)/process_variable_definition.o process_variable_definition.c 

$(TARGET)/process_target_definition.o : process_target_definition.c bake.h 
	$(C99) $(CFLAGS) -c -o $(TARGET)/process_target_definition.o process_target_definition.c 

echostuff : 
	echo $(TARGET)

clean :
	rm -f ../target/*
	rm -f ../testtarget/*
	rm -f bake
	rm -f bakeD
	rm -f test
	rm -f testD
	rm -f ../tests/test
	rm -f ../tests/testD


test : $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TARGET)/string_modifiers.o
	$(C99) $(CFLAGS) -o $(TESTLOC)/test $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TARGET)/string_modifiers.o -lcunit 
	$(C99) $(CFLAGS) -o test $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TARGET)/string_modifiers.o -lcunit 

$(TESTTARGET)/test.o : $(TESTLOC)/test.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test.o $(TESTLOC)/test.c 

$(TESTTARGET)/test_small_string_modifiers.o : $(TESTLOC)/test_small_string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_small_string_modifiers.o $(TESTLOC)/test_small_string_modifiers.c 

$(TESTTARGET)/test_moderate_string_modifiers.o : $(TESTLOC)/test_moderate_string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTLOC)/test_moderate_string_modifiers.c 

$(TESTTARGET)/test_substring.o : $(TESTLOC)/test_substring.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_substring.o $(TESTLOC)/test_substring.c 

$(TESTTARGET)/test_expand_variable_functions.o : $(TESTLOC)/test_expand_variable_functions.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_expand_variable_functions.o $(TESTLOC)/test_expand_variable_functions.c 



##################DEBUG MODE#########################

bakeD : $(TARGET)/bakeD.o $(TARGET)/process_bakefileD.o $(TARGET)/expand_variablesD.o $(TARGET)/nextlineD.o $(TARGET)/string_modifiersD.o $(TARGET)/process_variable_definitionD.o $(TARGET)/process_target_definitionD.o
	$(C99) $(CFLAGS) -g -o bake -ggdb $(TARGET)/bakeD.o $(TARGET)/process_bakefileD.o $(TARGET)/expand_variablesD.o $(TARGET)/nextlineD.o $(TARGET)/string_modifiersD.o $(TARGET)/process_variable_definitionD.o $(TARGET)/process_target_definitionD.o 


$(TARGET)/bakeD.o : bake.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/bakeD.o bake.c

$(TARGET)/process_bakefileD.o : process_bakefile.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/process_bakefileD.o process_bakefile.c

$(TARGET)/nextlineD.o : nextline.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/nextlineD.o nextline.c

$(TARGET)/string_modifiersD.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/string_modifiersD.o string_modifiers.c

$(TARGET)/expand_variablesD.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/expand_variablesD.o expand_variables.c

$(TARGET)/process_variable_definitionD.o : process_variable_definition.c bake.h 
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/process_variable_definitionD.o process_variable_definition.c 

$(TARGET)/process_target_definitionD.o : process_target_definition.c bake.h 
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/process_target_definitionD.o process_target_definition.c 



##############DEBUG MODE ###########################

testD : $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TARGET)/string_modifiersD.o
	$(C99) $(CFLAGS) -g -o $(TESTLOC)/test $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TARGET)/string_modifiersD.o -lcunit 
	$(C99) $(CFLAGS) -g -o test $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TARGET)/string_modifiersD.o -lcunit 

$(TESTTARGET)/testD.o : $(TESTLOC)/test.c $(TESTLOC)/test.h
	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/testD.o $(TESTLOC)/test.c 

$(TESTTARGET)/test_small_string_modifiersD.o : $(TESTLOC)/test_small_string_modifiers.c $(TESTLOC)/test.h
	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTLOC)/test_small_string_modifiers.c 

$(TESTTARGET)/test_moderate_string_modifiersD.o : $(TESTLOC)/test_moderate_string_modifiers.c $(TESTLOC)/test.h
	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTLOC)/test_moderate_string_modifiers.c 

$(TESTTARGET)/test_substringD.o : $(TESTLOC)/test_substring.c $(TESTLOC)/test.h
	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_substringD.o $(TESTLOC)/test_substring.c 

$(TESTTARGET)/test_expand_variable_functionsD.o : $(TESTLOC)/test_expand_variable_functions.c $(TESTLOC)/test.h
	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_expand_variable_functionsD.o $(TESTLOC)/test_expand_variable_functions.c 

# $(TESTTARGET)/string_modifiersD.o : string_modifiers.c bake.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/string_modifiersD.o string_modifiers.c

#1. dollar sign is invisible
#2. $ () means $is invisible and carry on
#3. $( ) any space inside becomes an unrecognisable variable
#4. $( this is undefined and throws an error.


#<<<<<<< HEAD:makefile
#=======


#Files to ADD: bake.c 	bake.h expand_variables.c 	globals.c 	nextline.c 	process_variable_definition.c 	string_modifiers.c 	process_bakefile.c





#A Makefile to build our 'haversine' project
# PROJECT = haversine
# HEADERS = $(PROJECT).h

# C99     = cc -std=c99
# CFLAGS  = -Wall -pedantic -Werror

# haversine : haversine.o haversine_function.o degrees_to_radians.o radians_to_degrees.o valid_location.o
#     cc -std=c99 -Wall -pedantic -Werror -o haversine haversine.o haversine_function.o degrees_to_radians.o radians_to_degrees.o valid_location.o -lm

# haversine.o : haversine.c $(HEADERS)
#     cc -std=c99 -Wall -pedantic -Werror -c haversine.c

# haversine_function.o : haversine_function.c $(HEADERS)
#     cc -std=c99 -Wall -pedantic -Werror -c haversine_function.c

# degrees_to_radians.o : degrees_to_radians.c $(HEADERS)
#     cc -std=c99 -Wall -pedantic -Werror -c degrees_to_radians.c

# radians_to_degrees.o : radians_to_degrees.c $(HEADERS)
#     cc -std=c99 -Wall -pedantic -Werror -c radians_to_degrees.c

# valid_location.o : valid_location.c $(HEADERS)
#     cc -std=c99 -Wall -pedantic -Werror -c valid_location.c


#make dependencies, runs bash
#specifies relationship between the pieces of a project
