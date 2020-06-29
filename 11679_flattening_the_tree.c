#include <stdio.h>
int arr[1024];
void sqe(int cur, int n){
    if(cur > n){
        return;
    }
    sqe(cur * 2, n);
    if(cur != n){
        printf("%d ", arr[cur]);
    }
    else{
        printf("%d", arr[cur]);
    }

    sqe(cur * 2 + 1, n);

    return;
}

int main(){

    int n, i;
    scanf("%d", &n);
    for(i = 1;i <= n; i++) {
    scanf("%d", &arr[i]);
    }

    sqe(1, n);
    printf("\n");

    return 0;
}
