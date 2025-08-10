CC = gcc
CFLAGC = -o 
NAME = main
HELPERS = ./helpers/getword.c ./helpers/addtree.c ./helpers/treeprint.c

all : $(NAME)

$(NAME) : 
	$(CC) main.c $(HELPERS) $(CFLAGC) main -g

clean : 
	rm -rf $(NAME) main.dSYM

.PHONEY : $(NAME) clean

