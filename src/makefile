
# CITS2002 Project 2018 
# Names:              Alex Franzis,   Kieren Underwood
# Student numbers:    21988858,       21315543 
# 

C99 = cc -std=c99
CFLAGS = -Wall -pedantic -Werror

#First call make bake to compile
#then run program ./bake <args>
#make clean to delete all object and executable files including the bake program

###################test########################

#process_target_line

################Compound Targets#######################

bake : bake.o internal_representation.o expand_variables.o nextline.o string_modifiers.o process_definitions.o  globals.o process_target_line.o
	$(C99) $(CFLAGS) -o bake bake.o internal_representation.o expand_variables.o nextline.o string_modifiers.o process_definitions.o  globals.o process_target_line.o

##################Base Targets#########################



bake.o : bake.c bake.h
	$(C99) $(CFLAGS) -c -o bake.o bake.c

internal_representation.o : internal_representation.c bake.h
	$(C99) $(CFLAGS) -c -o internal_representation.o internal_representation.c

nextline.o : nextline.c bake.h
	$(C99) $(CFLAGS) -c -o nextline.o nextline.c

string_modifiers.o : string_modifiers.c bake.h
	$(C99) $(CFLAGS) -c -o string_modifiers.o string_modifiers.c

expand_variables.o : expand_variables.c bake.h
	$(C99) $(CFLAGS) -c -o expand_variables.o expand_variables.c

process_definitions.o : process_definitions.c bake.h 
	$(C99) $(CFLAGS) -c -o process_definitions.o process_definitions.c 

process_target_line.o : process_target_line.c bake.h 
	$(C99) $(CFLAGS) -c -o process_target_line.o process_target_line.c 

globals.o : globals.c bake.h 
	$(C99) $(CFLAGS) -c -o globals.o globals.c 

clean :
	#rm -f bake
	rm -f *.o

