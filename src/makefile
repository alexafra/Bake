C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror
TESTLOC = ../tests
TARGET = ../target

TESTTARGET = ../testtarget


###################test########################

#process_target_line

################Compound Targets#######################

bake : $(TARGET)/bake.o $(TARGET)/internal_representation.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_definitions.o  $(TARGET)/globals.o $(TARGET)/process_target_line.o
	$(C99) $(CFLAGS) -o bake $(TARGET)/bake.o $(TARGET)/internal_representation.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_definitions.o  $(TARGET)/globals.o $(TARGET)/process_target_line.o



##################Base Targets#########################

$(TARGET)/bake.o : bake.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/bake.o bake.c

$(TARGET)/internal_representation.o : internal_representation.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/internal_representation.o internal_representation.c

$(TARGET)/nextline.o : nextline.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/nextline.o nextline.c

$(TARGET)/string_modifiers.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/string_modifiers.o string_modifiers.c

$(TARGET)/expand_variables.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -c -o $(TARGET)/expand_variables.o expand_variables.c

$(TARGET)/process_definitions.o : process_definitions.c bake.h 
	$(C99) $(CFLAGS) -c -o $(TARGET)/process_definitions.o process_definitions.c 

$(TARGET)/process_target_line.o : process_target_line.c bake.h 
	$(C99) $(CFLAGS) -c -o $(TARGET)/process_target_line.o process_target_line.c 

$(TARGET)/globals.o : globals.c bake.h 
	$(C99) $(CFLAGS) -c -o $(TARGET)/globals.o globals.c 



echostuff : 
	echo $(TARGET)

clean :
	rm -f ../target/*
	rm -f ../testtarget/*
	#rm -f bake
	rm -f bakeD
	rm -f test
	rm -f testD
	rm -f ../tests/test
	rm -f ../tests/testD


test : $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TARGET)/expand_variables.o $(TESTTARGET)/test_process_definitions.o $(TESTTARGET)/test_target_lines.o $(TARGET)/process_definitions.o $(TARGET)/string_modifiers.o $(TARGET)/process_target_line.o $(TARGET)/globals.o 

	$(C99) $(CFLAGS) -o $(TESTLOC)/test $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TESTTARGET)/test_process_definitions.o $(TESTTARGET)/test_target_lines.o $(TARGET)/string_modifiers.o $(TARGET)/process_definitions.o $(TARGET)/expand_variables.o $(TARGET)/process_target_line.o $(TARGET)/globals.o  -lcunit 
	$(C99) $(CFLAGS) -o test $(TESTTARGET)/test.o $(TESTTARGET)/test_small_string_modifiers.o $(TESTTARGET)/test_moderate_string_modifiers.o $(TESTTARGET)/test_substring.o $(TESTTARGET)/test_expand_variable_functions.o $(TESTTARGET)/test_process_definitions.o $(TESTTARGET)/test_target_lines.o $(TARGET)/string_modifiers.o $(TARGET)/process_definitions.o $(TARGET)/expand_variables.o $(TARGET)/process_target_line.o $(TARGET)/globals.o  -lcunit 

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

$(TESTTARGET)/test_process_definitions.o : $(TESTLOC)/test_process_definitions.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_process_definitions.o $(TESTLOC)/test_process_definitions.c 

$(TESTTARGET)/test_target_lines.o : $(TESTLOC)/test_target_lines.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_target_lines.o $(TESTLOC)/test_target_lines.c 


##################DEBUG MODE#########################

bakeD : $(TARGET)/bakeD.o $(TARGET)/internal_representationD.o $(TARGET)/expand_variablesD.o $(TARGET)/nextlineD.o $(TARGET)/string_modifiersD.o $(TARGET)/process_definitionsD.o $(TARGET)/process_target_lineD.o $(TARGET)/globalsD.o 
	$(C99) $(CFLAGS) -g -o bake -ggdb $(TARGET)/bakeD.o $(TARGET)/internal_representationD.o $(TARGET)/expand_variablesD.o $(TARGET)/nextlineD.o $(TARGET)/string_modifiersD.o $(TARGET)/process_definitionsD.o $(TARGET)/process_target_lineD.o $(TARGET)/globalsD.o 


$(TARGET)/bakeD.o : bake.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/bakeD.o bake.c

$(TARGET)/internal_representationD.o : internal_representation.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/internal_representationD.o internal_representation.c

$(TARGET)/nextlineD.o : nextline.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/nextlineD.o nextline.c

$(TARGET)/string_modifiersD.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/string_modifiersD.o string_modifiers.c

$(TARGET)/expand_variablesD.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/expand_variablesD.o expand_variables.c

$(TARGET)/process_definitionsD.o : process_definitions.c bake.h 
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/process_definitionsD.o process_definitions.c 

$(TARGET)/process_target_lineD.o : process_target_line.c bake.h 
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/process_target_lineD.o process_target_line.c 

$(TARGET)/globalsD.o : globals.c bake.h 
	$(C99) $(CFLAGS) -g -c -o $(TARGET)/globalsD.o globals.c




##############DEBUG MODE ###########################

# testD : $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TARGET)/expand_variablesD.o $(TESTTARGET)/test_process_definitionsD.o $(TARGET)/string_modifiersD.o $(TARGET)/process_definitionsD.o $(TARGET)/process_target_lineD.o $(TARGET)/globalsD.o 
	
# 	$(C99) $(CFLAGS) -g -o $(TESTLOC)/test $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TESTTARGET)/test_process_definitionsD.o $(TARGET)/string_modifiersD.o $(TARGET)/expand_variablesD.o $(TARGET)/process_definitionsD.o $(TARGET)/process_target_lineD.o $(TARGET)/globalsD.o  -lcunit 
	
# 	$(C99) $(CFLAGS) -g -o test $(TESTTARGET)/testD.o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTTARGET)/test_substringD.o $(TESTTARGET)/test_expand_variable_functionsD.o $(TESTTARGET)/test_process_definitionsD.o $(TARGET)/string_modifiersD.o $(TARGET)/expand_variablesD.o $(TARGET)/process_definitionsD.o $(TARGET)/process_target_lineD.o $(TARGET)/globalsD.o  -lcunit 

# $(TESTTARGET)/testD.o : $(TESTLOC)/test.c $(TESTLOC)/test.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/testD.o $(TESTLOC)/test.c 

# $(TESTTARGET)/test_small_string_modifiersD.o : $(TESTLOC)/test_small_string_modifiers.c $(TESTLOC)/test.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_small_string_modifiersD.o $(TESTLOC)/test_small_string_modifiers.c 

# $(TESTTARGET)/test_moderate_string_modifiersD.o : $(TESTLOC)/test_moderate_string_modifiers.c $(TESTLOC)/test.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_moderate_string_modifiersD.o $(TESTLOC)/test_moderate_string_modifiers.c 

# $(TESTTARGET)/test_substringD.o : $(TESTLOC)/test_substring.c $(TESTLOC)/test.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_substringD.o $(TESTLOC)/test_substring.c 

# $(TESTTARGET)/test_expand_variable_functionsD.o : $(TESTLOC)/test_expand_variable_functions.c $(TESTLOC)/test.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_expand_variable_functionsD.o $(TESTLOC)/test_expand_variable_functions.c 

# $(TESTTARGET)/test_process_definitionsD.o : $(TESTLOC)/test_process_definitions.c bake.h
# 	$(C99) $(CFLAGS) -g -c -o $(TESTTARGET)/test_process_definitionsD.o $(TESTLOC)/test_process_definitions.c 



#1. dollar sign is invisible
#2. $ () means $is invisible and carry on
#3. $( ) any space inside becomes an unrecognisable variable
#4. $( this is undefined and throws an error.


