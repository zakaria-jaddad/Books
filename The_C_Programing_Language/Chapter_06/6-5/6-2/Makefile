CC = gcc
CFLAGC = -o 
NAME = main
HELPERS = ./helpers/count_words.c ./helpers/ft_split.c ./helpers/ft_strchr.c ./helpers/ft_strlen.c ./helpers/get_current_word.c ./helpers/read_file.c ./helpers/ft_strncpy.c

all : $(NAME)

$(NAME) : 
	$(CC) main.c $(HELPERS) $(CFLAGC) main -g

clean : 
	rm -rf $(NAME) main.dSYM

.PHONEY : $(NAME) clean

