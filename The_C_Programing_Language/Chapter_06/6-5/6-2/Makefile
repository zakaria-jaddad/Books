CC = gcc
CFLAGC = -o 
NAME = main
HELPERS = ./helpers/addlist.c ./helpers/addtree.c ./helpers/count_words.c ./helpers/ft_split.c ./helpers/ft_strchr.c ./helpers/ft_strlen.c ./helpers/ft_strncpy.c ./helpers/get_current_word.c ./helpers/printlist.c ./helpers/read_file.c ./helpers/treeprint.c

all : $(NAME)

$(NAME) : clean
	$(CC) main.c $(HELPERS) $(CFLAGC) main -g

clean : 
	rm -rf $(NAME) main.dSYM

.PHONEY : $(NAME) clean

