#ifndef header_h
#define header_h

#define VAR_SEPARATOR ","

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>

char **ft_split(char *str, char *charset);
char *ft_strchr(char *charset, int c);
char *get_current_word(char *str, char *charset, int index);
char *ft_strncpy(char *dst, char *src, int length);
int count_words(char *str, char *charset);
int ft_strlen(char *str, char *charset);

char *read_file(char *file_path);
#endif
