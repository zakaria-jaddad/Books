#ifndef POINT_H
#define POINT_H

#define XMAX 220
#define YMAX 200

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point makepoint(int x, int y);
struct point addpoints(struct point p1, struct point p2);
int ptinrect(struct point p, struct rec r);
struct rec canonrect(struct rec r);

struct point {
  int x;
  int y;
};

struct rec {
  struct point p1;
  struct point p2;
};

#endif
