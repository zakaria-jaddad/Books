#include "./include/syscalls.h"

/* closedir: close directory opened by opendir */
void my_closedir(MY_DIR *dp)
{
  if (dp != NULL)
  {
    close(dp->fd);
    free(dp);
  }
}
