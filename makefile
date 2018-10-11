#A Makefile to build our 'haversine' project
PROJECT = haversine
HEADERS = $(PROJECT).h

C99     = cc -std=c99
CFLAGS  = -Wall -pedantic -Werror

haversine : haversine.o haversine_function.o degrees_to_radians.o radians_to_degrees.o valid_location.o
    cc -std=c99 -Wall -pedantic -Werror -o haversine haversine.o haversine_function.o degrees_to_radians.o radians_to_degrees.o valid_location.o -lm

haversine.o : haversine.c $(HEADERS)
    cc -std=c99 -Wall -pedantic -Werror -c haversine.c

haversine_function.o : haversine_function.c $(HEADERS)
    cc -std=c99 -Wall -pedantic -Werror -c haversine_function.c

degrees_to_radians.o : degrees_to_radians.c $(HEADERS)
    cc -std=c99 -Wall -pedantic -Werror -c degrees_to_radians.c

radians_to_degrees.o : radians_to_degrees.c $(HEADERS)
    cc -std=c99 -Wall -pedantic -Werror -c radians_to_degrees.c

valid_location.o : valid_location.c $(HEADERS)
    cc -std=c99 -Wall -pedantic -Werror -c valid_location.c


#make dependencies, runs bash
#specifies relationship between the pieces of a project
