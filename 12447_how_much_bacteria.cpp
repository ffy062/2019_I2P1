#include <stdio.h>

int arr[33][1000003];

int main() {
    int b, t, l, r, cnt;
    int i, j;

    scanf("%d %d", &b, &t);
    for(i = 0; i < 32; ++i) {
        arr[i][0] = 0;
    }
    for(i = 0; i < b; ++i) {
        int type;
        scanf("%d", &type);
        for(j = 0; j < 32; ++j) {
            arr[j][i + 1] = arr[j][i];
        }
        arr[type][i + 1]++;
    }

    while(t--) {
        scanf("%d %d", &l, &r);
        cnt = 0;
        for(i = 0; i < 32; ++i) {
            if(arr[i][r + 1] -arr[i][l])
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
