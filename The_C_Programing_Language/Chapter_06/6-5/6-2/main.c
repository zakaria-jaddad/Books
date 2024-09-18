#include "./includes/header.h"
#include "includes/tnode.h"
#include <stdio.h>
#include <string.h>

/*
 * TODO:
 * []: Skip comments
 * []: indecates function names
 *
 */

int is_data_type(char *str)
{
  char *data_types[] = {"char", "double", "float", "int",
                        "long", "short",  "void",  0};
  for (int i = 0; data_types[i]; i++)
  {
    if (strcmp(data_types[i], str) == 0)
      return 1;
  }
  return 0;
}

int is_end_declaration(char *str)
{
  char *end_declaration[] = {";", "=", 0};
  for (int i = 0; end_declaration[i]; i++)
  {
    if (strcmp(end_declaration[i], str) == 0)
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Error: Invalid arguments\n");
    return EXIT_FAILURE;
  }

  struct tnode *root;
  int n = atoi(argv[1]);
  int var_flag = 0;
  char *file_path = argv[2];
  char *content = read_file(file_path);
  char *charset = " \n\t,;<>*{}[]()|\"\"/\\-+!@#$&^:`~";
  char **double_string = ft_split(content, charset);

  root = NULL;
  for (int i = 0; double_string[i]; i++)
  {
    if (!is_data_type(double_string[i]) && var_flag)
    {
      printf("%s\n", double_string[i]);
      if (is_end_declaration(double_string[i + 1]))
        var_flag = 0;
    }
    else if (is_data_type(double_string[i]))
      var_flag = 1;
  }

  return EXIT_SUCCESS;
}
