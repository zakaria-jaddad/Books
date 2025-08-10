#include "header.h"

static Header base;
static Header *freep = NULL;
static Header *morecore(unsigned nu);

/*
int	main(int argc, char **argv)
{
  char *hello;

  hello = (char *) my_malloc(sizeof(char) * 7);
  hello = "hello";
  printf("allocated string is  = %s\n", hello);
  return (EXIT_SUCCESS);
}
*/

/* malloc general-purpost storage allocator */
void *my_malloc(unsigned nbytes)
{
  unsigned nunits;

  Header *p, *prevp;
  Header *morecore(unsigned);

  if (nbytes == 0 || nbytes >= NALLOC * 3)
  {
    fprintf(stderr, "my_malloc: size too big\n");
    return NULL;
  }
  nunits = (nbytes + sizeof(Header) - 1) / sizeof(union header) + 1;
  if ((prevp = freep) == NULL)
  {
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr)
  {
    if (p->s.size >= nunits) /* big enough */
    {
      if (p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else
      {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *) (p + 1);
    }
    if (p == freep) /* wrapped around free list */
      if ((p = morecore(nunits)) == NULL)
        return ((void *) NULL); /* none left */
  }
}

/* morecore: alk system for more memory */
static Header *morecore(unsigned nu)
{
  Header *up;

  char *cp, *sbrk(int);
  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *) -1) /* no space at all */
    return (NULL);
  up = (Header *) cp;
  up->s.size = nu;
  my_free((void *) (up + 1));
  return (freep);
}

/* my_free: put block ap in free list */
void my_free(void *ap)
{
  Header *bp, *p;
  bp = (Header *) ap - 1; /* point to bloc header */
  if (bp->s.size == 0 || bp->s.size == NALLOC * 3)
  {
    fprintf(stderr, "Error(free): invalid block size %u\n", bp->s.size);
    return;
  }
  for (p = freep; (bp > p && bp < p->s.ptr); p = p->s.ptr)
  {
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break; /* freed block at stat or end of arena */
  }
  if (bp + bp->s.size == p->s.ptr) /* join to upper nbr */
  {
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  }
  else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp)
  {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  }
  else
    p->s.ptr = bp;
  freep = p;
}
