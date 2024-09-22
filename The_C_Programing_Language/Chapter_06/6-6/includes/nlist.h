#ifndef NLIST_H
#define NLIST_H

#include "string.h"
#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 101

/* table entry: */
struct nlist
{
  struct nlist *next; /* next entry in chain */
  char *name;         /* defined name */
  char *defn;         /* replacement text */
};

/* pointer table */
struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s */
unsigned int hash(char *s);

/*
 * lookup: look for string s in hashtab,
 * look for the nlist node name if equal to s.
 * returns:
 *  -> pointer to nlist if found
 *  -> NULL if not fount
 */
struct nlist *lookup(char *s);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn);

/* undev : remove name and defn from hashtab */
void undef(char *name, char *def);

#endif
