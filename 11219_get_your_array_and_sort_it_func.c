#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmp(const int * a,const int * b){

    return *a - *b;
}

void my_sort(int* B){
    int * a;
    a = *B;
    qsort(a + 1, *a, sizeof(a[0]), cmp);

    return;
}
