#include "header.h"

int main(void) {

  struct rec screen;
  struct point middle;

  screen.p1 = makepoint(0, 0);
  screen.p2 = makepoint(XMAX, YMAX);

  int middle_x = (screen.p1.x + screen.p2.x) / 2;
  int middle_y = (screen.p1.y + screen.p2.y) / 2;

  middle = makepoint(middle_x, middle_y);

  return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {

  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

/* addpoints: add two points */
struct point addpoints(struct point p1, struct point p2) {

  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rec r) {
  return p.x >= r.p1.x && p.x < r.p2.x && p.y >= r.p1.y && p.y < r.p2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rec canonrect(struct rec r) {
  struct rec temp;
  temp.p1.x = min(r.p1.x, r.p2.x);
  temp.p1.y = min(r.p1.y, r.p2.y);
  temp.p2.x = max(r.p1.x, r.p2.x);
  temp.p2.y = max(r.p1.y, r.p2.y);
  return temp;
}
