
CC = gcc
CFLAGS = -o main 
RUNMAIN = ./main

SRC = main.c ./alloc/alloc.c ./getline/getline.c ./qsort/qsort.c

main: $(SRC)	
	$(CC) $(SRC) $(CFLAGS)
	$(RUNMAIN)

clean : 
	rm -rf main

.PHONY: all clean
