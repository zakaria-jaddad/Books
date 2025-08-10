#include "../includes/ft_split.h"
#include "../includes/header.h"
#include "../includes/nlist.h"

/* double_arr_counter: counts how many element  inthe array */
int double_arr_counter(char **arr)
{
  int counter = 0;
  int i = 0;
  while (arr[i])
  {
    counter++;
    i++;
  }
  return counter;
}

int main(void)
{
  char *input;
  char **def_name;
  char *charset = " \t";

  while (1)
  {
    puts("a to add definition");
    puts("d to delete definition");
    puts("f to find definition");
    input = ft_getline(LINE_LIMIT);
    if (input[0] == 'a')
    {
      input = ft_getline(LINE_LIMIT);
      if (*input == 0)
        continue;
      def_name = ft_split(input, charset);
      if (double_arr_counter(def_name) != 2)
      {
        puts("Unexpected argument");
        puts("ERROR: expected <def> <name>");
        continue;
      }
      char *name = def_name[0];
      char *def = def_name[1];
      struct nlist *def_name_node = install(name, def);
      printf("%s %s Got added successfully\n", name, def);
    }
    else if (input[0] == 'd')
    {
      input = ft_getline(LINE_LIMIT);
      if (*input == 0)
        continue;
      def_name = ft_split(input, charset);
      if (double_arr_counter(def_name) != 1)
      {
        puts("Unexpected argument");
        puts("ERROR: expected <def> <name>");
        continue;
      }
      char *name = def_name[0];
      char *def = def_name[1];
      struct nlist *node = lookup(name);
      if (node == NULL)
      {
        puts("Could't find definition");
        continue;
      }
      undef(node->name, node->defn);
    }
    else if (input[0] == 'f')
    {
      input = ft_getline(LINE_LIMIT);
      if (*input == 0)
        continue;
      def_name = ft_split(input, charset);
      if (double_arr_counter(def_name) != 1)
      {
        puts("Unexpected argument");
        puts("ERROR: expected <def> <name>");
        continue;
      }
      char *name = def_name[0];
      struct nlist *node = lookup(name);
      if (node == NULL)
      {
        puts("Could't find definition");
        continue;
      }
      printf("%s %s \n", node->name, node->defn);
    }
  }
  return EXIT_SUCCESS;
}

/* while (1) */
/* { */
/*   input = ft_getline(LINE_LIMIT); */
/*   if (*input == 0) */
/*     break; */
/*   def_name = ft_split(input, charset); */
/*   if (double_arr_counter(def_name) != 2) */
/*   { */
/*     puts("Unexpected argument"); */
/*     puts("ERROR: expected <def> <name>"); */
/*     continue; */
/*   } */
/*   char *name = def_name[0]; */
/*   char *def = def_name[1]; */
/*   struct nlist *def_name_node = install(name, def); */
/*   struct nlist *node = lookup(name); */
/*   puts(hashtab[17]->name); */
/*   puts(hashtab[17]->defn); */
/*   if (node == NULL) */
/*   { */
/*     puts("definition not found"); */
/*     continue; */
/*   } */
/*   printf("definition name: %s\n", node->name); */
/*   printf("definition value: %s\n", node->defn); */
/* } */
/**/
