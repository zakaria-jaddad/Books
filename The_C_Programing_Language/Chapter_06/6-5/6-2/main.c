#include "./includes/header.h"
#include "includes/tnode.h"
#include <stdio.h>
#include <string.h>

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

int is_nex_var(char *str)
{
  while (*str)
  {
    if (ft_strchr(VAR_SEPARATOR, *str) != NULL)
      return 1;
    str++;
  }
  return 0;
}

char *format_string(char *str)
{
  int i = 0;
  int length = strlen(str);
  char *formatted_string = malloc(sizeof(char) * length + 1);
  if (formatted_string == NULL)
    return 0;

  while (*str)
  {
    if (ft_strchr(VAR_SEPARATOR, *str) != NULL)
      break;
    formatted_string[i++] = *str++;
  }
  formatted_string[i] = 0;
  return formatted_string;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Error: Invalid arguments\n");
    return EXIT_FAILURE;
  }

  struct list_node *head;
  int n = atoi(argv[1]);
  int var_flag = 0;
  char *file_path = argv[2];
  char *content = read_file(file_path);
  char *charset = " \n\t<>;*{}[]()|\"\"/\\-\'+!@#$&^:`~";
  char **double_string = ft_split(content, charset);

  head = NULL;
  for (int i = 0; double_string[i]; i++)
  {
    if (!is_data_type(double_string[i]) && var_flag)
    {
      /* printf("%s\n", format_string(double_string[i])); */
      if (strcmp(VAR_SEPARATOR, double_string[i]) != 0)
        head = addlist(head, format_string(double_string[i]), n);
      if (is_nex_var(double_string[i]))
        var_flag = 1;
      else
        var_flag = 0;
    }
    else if (is_data_type(double_string[i]))
      var_flag = 1;
  }
  print_list(head);

  return EXIT_SUCCESS;
}
