#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t, n, i, j, k, l, count = 0, flag = 1, point = 0, in[101]={0};
   float p[100][2];

   scanf("%d", &t);

   for(i = 0; i < t; i++, count = 0){
    scanf("%d", &n);

    for(j = 0; j < n; j++){
        scanf("%f%f", &p[j][0], &p[j][1]);
    }

    // find all lines which pass through at least points 
    // may count the same line more than once
    for(j = 0; j < n; j++){
        for(k = j + 1; k < n; k++){
            flag = 1;
            point = 0;
            for(l = 0; l < n; l++){
                if(l == j || l == k){
                    continue;
                }

               if((p[l][0]-p[k][0]) * (p[k][1]-p[j][1]) == (p[k][0]-p[j][0]) * (p[l][1]-p[k][1])){
                    if(flag == 1){
                        point = 3;
                    }
                    if(flag == 0){
                        point++;
                    }
                    flag = 0;
                    //printf("%d %d %d \n",j,k,l);
                }
            }
            in[point]++;
        }
    }

    // handle the lines which count more than once
    for(j = 3; j < 101; j++){
        in[j] = in[j] * 2 / j / (j-1);
        count += in[j];
        in[j] = 0;
    }
    printf("%d\n", count);
   }
    return 0;
}
