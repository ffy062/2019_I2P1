#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pos[26][2], t, n, x, c[5]={0}, r[5] = {0}, ul, ur, flag;
    for(int i = 0 ;i < 5; i++){
        for(int j = 0; j < 5; j++){
         scanf("%d", &x);
         pos[x][0] = i;
         pos[x][1] = j;
        }
    }
    scanf("%d", &t);
    for(int i = 1,flag = 0;i <= t; i++, flag = 0){
        for(int j = 0, ul = 0, ur = 0;j < 5; j++ ,ul = 0, ur = 0){
            c[j] = 0;
            r[j] = 0;
        }
        scanf("%d", &n);
        for(j = 1; j <= n; j++){
            scanf("%d", &x);
            c[pos[x][0]]++;
            r[pos[x][1]]++;
            if(pos[x][0] == pos[x][1]){
                ul++;
            }
            if(pos[x][0] + pos[x][1] == 4){
                ur++;
            }
            if(c[0] == 5 ||c[1] == 5 || c[2] == 5 || c[3] == 5 || c[4] == 5 || r[0] == 5 ||
            r[1] == 5 || r[2] == 5 || r[3] == 5 || r[4] == 5 || ul ==5 || ur == 5){
                printf("Case #%d: %d\n", i, j);
                flag = 1;
                break;
            }
        }
        for(j = j + 1 ; j <= n; j++){
            scanf("%d", &x);
        }
        if(flag == 0){
            printf("Case #%d: Not yet \\(^o^)/\n", i);
        }
    }

    return 0;
}
