#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666 /* RW for owner, group and others */

typedef struct _iobuf
{
  int cnt;    /* characters left counter */
  char *ptr;  /* next character position */
  char *base; /* location of buffer */
  int flag;   /* mode of file access */
  int fd;     /* file descriptor */
} MY_FILE;

extern MY_FILE _iob[OPEN_MAX];

#ifdef _LIBCPP_STDIO_H
#undef _LIBCPP_STDIO_H
#endif

#ifdef stdin
#undef stdin
#endif
#define stdin (&_iob[0])

#ifdef stdout
#undef stdout
#endif
#define stdout (&_iob[1])

#ifdef stderr
#undef stderr
#endif
#define stderr (&_iob[2])

enum _flags
{
  _READ = 01,  /* file open for reading */
  _WRITE = 02, /* file open for writing */
  _UNBUF = 04, /* file is unbuffered */
  _EOF = 010,  /* EOF has accurred on the file */
  _ERR = 020   /* error occurred on this file*/
};

int _fillbuf(MY_FILE *);
int _flushbuf(int, MY_FILE *);

/*
 * The feof() function in C is used to check if the end-of-file (EOF) indicator
 * has been reached for a given file stream. It returns a non-zero value if the
 * end-of-file indicator is set, indicating that the end of the file has been
 * reached. Otherwise, it returns zero.
 *
 * In stdio feof() is a function not a macro function, no idea why the author
 * did it like this.
 * int feof(FILE *);
 */
#define feof(p) ((p->flag & _EOF) != 0)

/*
 * The ferror() also a function in C not a macro
 * check if error has accurred in the given file.
 */
#define ferror(p) ((p->flag & _ERR) != 0)
#define fileno(p) (p->fd)

#define getc(p) ((--(p)->cnt >= 0) ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar() getc(stdin)
#define putchar(x) putc(x, stdout)

#endif
