#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, sum, i;
    int ans[34] = {0};

    scanf("%x%x", &x, &y);
    sum = x + y;
    for(i = 0; sum > 0; i++){
        ans[i] = sum % 2;
        sum /= 2;
    }

    for(i =  i - 1; i >=0 ; i--){
        printf("%d", ans[i]);
    }

    return 0;
}
