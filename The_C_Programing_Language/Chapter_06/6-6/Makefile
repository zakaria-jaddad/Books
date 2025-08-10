CFLAGS = -o

CC = gcc

FT_SPLIT = ./src/ft_split/count_words.c ./src/ft_split/ft_split.c ./src/ft_split/ft_strchr.c ./src/ft_split/ft_strlen.c ./src/ft_split/ft_strncpy.c ./src/ft_split/get_current_word.c

CFILES = ./src/ft_getline.c ./src/hash.c ./src/install.c ./src/lookup.c ./src/main.c ./src/undef.c

NAME = main

all: ${NAME}

$(NAME): 
	$(CC) $(CFILES) $(FT_SPLIT) $(CFLAGS) $@

clean: 
	rm -rf $(NAME)

re: clean $(NAME)
