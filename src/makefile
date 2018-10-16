C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror
TESTLOC = ../tests
TARGET = ../target
TESTTARGET = ../testtarget

###################test########################

test : $(TESTTARGET)/test_string_modifiers.o $(TARGET)/string_modifiers.o
	$(C99) $(CFLAGS) -o $(TESTTARGET)/test_string_modifiers $(TESTTARGET)/test_string_modifiers.o $(TARGET)/string_modifiers.o -lcunit


$(TESTTARGET)/test_string_modifiers.o : $(TESTLOC)/test_string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o $(TESTTARGET)/test_string_modifiers.o $(TESTLOC)/test_string_modifiers.c 


################Compound Targets#######################

bake : $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o
	$(C99) $(CFLAGS) -o $(TARGET)/bake $(TARGET)/bake.o $(TARGET)/process_bakefile.o $(TARGET)/expand_variables.o $(TARGET)/nextline.o $(TARGET)/string_modifiers.o $(TARGET)/process_variable_definition.o $(TARGET)/process_target_definition.o

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




#<<<<<<< HEAD:makefile
#=======


#Files to ADD: bake.c 	bake.h expand_variables.c 	globals.c 	nextline.c 	process_variable_definition.c 	string_modifiers.c 	process_bakefile.c
>>>>>>> 29660dc240d074699e91d2e4c1b7b0312382176d:src/makefile






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
