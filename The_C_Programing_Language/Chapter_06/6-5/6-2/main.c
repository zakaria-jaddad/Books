#include "./includes/header.h"

/*
 * TODO:
 * []: Skip comments
 * []: indecates function names
 *
 */
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Error: Invalid arguments\n");
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);
  char *file_path = argv[2];

  char *content = read_file(file_path);

  char *charset = " \n\t,;<>*{}[]()|\"\"/\\-+!@#$&^:`~";
  char **double_string = ft_split(content, charset);
  for (int i = 0; i < 30; i++)
    printf("%s\n", double_string[i]);

  return EXIT_SUCCESS;
}
