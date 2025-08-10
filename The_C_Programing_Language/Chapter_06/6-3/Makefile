CC = gcc
CFLAGC = -o
NAME = main
HELPERS = ./helpers/getword.c ./helpers/binsearch.c

all : $(NAME)

$(NAME) : 
	$(CC) count_words.c $(HELPERS) $(CFLAGC) main

clean : 
	rm -rf $(NAME)

.PHONEY : $(NAME) clean

