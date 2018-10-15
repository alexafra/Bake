C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror


###################test########################

test : test_string_modifiers.o string_modifiers.o
	$(C99) $(CFLAGS) -o test_string_modifiers test_string_modifiers.o string_modifiers.o -lcunit


test_string_modifiers.o : test_string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c test_string_modifiers.c #-lcunit


################Compound Targets#######################

bake : bake.o process_bakefile.o expand_variables.o nextline.o string_modifiers.o process_variable_definition.o 
	$(C99) $(CFLAGS) -o bake bake.o process_bakefile.o expand_variables.o nextline.o string_modifiers.o process_variable_definition.o 

##################Base Targets#########################

bake.o : bake.c bake.h
	$(C99) $(CFLAGS) -c bake.c

process_bakefile.o : process_bakefile.c bake.h
	$(C99) $(CFLAGS) -c string_modifiers.c

nextline.o : nextline.c bake.h
	$(C99) $(CFLAGS) -c nextline.c

string_modifiers.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c string_modifiers.c

expand_variables.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -c expand_variables.c

process_variable_definition.o : process_variable_definition.c bake.h 
	$(C99) $(CFLAGS) -c process_variable_definition.c 






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
