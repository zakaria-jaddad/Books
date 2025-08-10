CC = gcc
CFLAGC = -o 
NAME = main
HELPERS = ./helpers/getword.c ./helpers/binsearch.c

all : $(NAME)

$(NAME) : 
	$(CC) count_words.c $(HELPERS) $(CFLAGC) main -g

clean : 
	rm -rf $(NAME) main.dSYM

.PHONEY : $(NAME) clean

