#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "function.h"

Point * ones_vec_1(int length){
  Point * pos;
  int i, a, b;
  pos = (Point *)malloc(length * sizeof(Point));
  for(i = 0;i < length; i++){
    scanf("%d%d", &a, &b);
    pos[i].x = a;
    pos[i].y = b;
  }

  return pos;
}

float compute_distance(Point* a, int first_id, int second_id){
    float ans;
    Point first_p, second_p;

    first_p = *(a + first_id);
    second_p = *(a + second_id);
    ans= sqrt((first_p.x-second_p.x) * (first_p.x-second_p.x) + (first_p.y-second_p.y) * (first_p.y-second_p.y));

    return ans;
}
