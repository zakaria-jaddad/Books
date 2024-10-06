#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

static void minscanf(const char *fmt, ...);
void minprintf(const char *fmt, ...);
int get_line(char *string, int limit);

int main(int argc, char *argv[])
{
  char *ptr = "42";
  printf("hello world | %s --> %p | strlen(ptr) = %d = %f | ptr[0] = \'%c\' = "
         "0x\\%x = 0x\\%x = o\\%o | %u%% \n",
         ptr, &ptr, (int)strlen(ptr), ((int)strlen(ptr) / 1.0), ptr[0], ptr[0],
         ptr[0], ptr[0], 4 - 10);
  minprintf(
      "hello world | %s --> %p | strlen(ptr) = %d = %f | ptr[0] = \'%c\' = "
      "0x\\%x = 0x\\%x = o\\%o | %u%%\n",
      ptr, &ptr, (int)strlen(ptr), ((int)strlen(ptr) / 1.0), ptr[0], ptr[0],
      ptr[0], ptr[0], 4 - 10);
  return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(const char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  const char *p;
  union u_tag
  {
    int ival;
    int cval;
    float fval;
    double dval;
    char *sval;
    unsigned int uival;
    unsigned int xval;
    unsigned int oval;
    void *pval;
  } type;

  va_start(ap, fmt); /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++)
  {
    if (*p != '%')
    {
      putchar(*p);
      continue;
    }
    switch (*++p)
    {
    case 'd':
      type.ival = va_arg(ap, int);
      printf("%d", type.ival);
      break;
    case 'f':
      type.dval = va_arg(ap, double);
      printf("%f", type.dval);
      break;
    case 'x':
      type.xval = va_arg(ap, unsigned int);
      printf("%x", type.xval);
      break;
    case 'X':
      type.xval = va_arg(ap, unsigned int);
      printf("%X", type.xval);
      break;
    case 'u':
      type.uival = va_arg(ap, unsigned int);
      printf("%u", type.uival);
      break;
    case 'o':
      type.oval = va_arg(ap, unsigned int);
      printf("%o", type.oval);
      break;
    case 'c':
      type.cval = va_arg(ap, int);
      putchar(type.cval);
      break;
    case 's':
      type.sval = va_arg(ap, char *);
      for (char *s = type.sval; *s; s++)
        putchar(*s);
      break;
    case 'p':
      type.sval = va_arg(ap, void *);
      printf("%p", type.pval);
      break;
    default:
      putchar(*p);
      break;
    }
    va_end(ap); /* clean up when done */
  }
}

static void minscanf(const char *fmt, ...)
{
  // ...
}

int get_line(char *string, int limit)
{
  int c, i;

  for (i = 0; i < limit - 1 && (c = getc(stdin)) != EOF && c != '\n'; i++)
  {
    *(string + i) = c;
  }

  if (c == '\n')
  {
    *(string + i) = c;
    i++;
  }
  *(string + i) = '\0';
  return i;
}
