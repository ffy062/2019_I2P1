#include <stdio.h>
#include <math.h>
float popu[6];
int markov(int city, float p, float (*matrix)[6]);

int main(){
    int i, j, t, n, ans = 0, count = 0;

    float matrix[6][6], p;
    scanf("%d", &t);

    while(t--){
        count = 0;
        ans = 0;
        scanf("%d", &n);
        for(i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                scanf("%f", &matrix[i][j]);
            }
        }
        for(i = 0;i < n; i++){
            scanf("%f", &popu[i]);
        }
        scanf("%f", &p);
        if(popu[0] <= p){
            ans = 1;
        }
        while(ans == 0){
             ans = markov(n, p, matrix);
             count++;
        }
        if(ans == -1){
            printf("Never\n");
        }
        else{
            printf("%d\n", count);
        }
    }

    return 0;
}


int markov(int city, float p, float (*matrix)[6]){
    float chg[6] = {0};
    int i, j;
    for(i = 0;i < city; i++){
        for(j = 0;j < city; j++){
            chg[i] += matrix[i][j] * popu[j];
        }
    }
    //printf("a = %f p = %f\n",chg[0],p);
    if(fabs(chg[0]-popu[0]) < 10E-8){
        return -1;
    }
    else if(chg[0] <= p){
        return 1;
    }
    else{
        for(i = 0;i < city; i++){
            popu[i] = chg[i];
        }
        return 0;
    }
}
