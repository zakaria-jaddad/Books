#include <math.h>
#include <stdio.h>

struct point {
  int x;
  int y;
} x, y, z;

struct rec {
  struct point p1;
  struct point p2;
};

int main(int argc, char **argv) {

  x.x = 10;
  x.y = 20;

  printf("x ---> %d\ny ---> %d\n", x.x, x.y);

  /* calculate distance */
  double distance;

  distance = sqrt((double)x.x * (double)x.x + (double)x.y * (double)x.y);

  /* screen */
  struct rec screen;
  screen.p1.x = 10;

  return 0;
}
