
CC = gcc
CFLAGS = -o main -g
RUNMAIN = ./main

SRC = main.c ./getline/getline.c ./qsort/qsort.c

main: $(SRC)	
	$(CC) $(SRC) $(CFLAGS)
	$(RUNMAIN)

clean : 
	rm -rf main

.PHONY: all clean
