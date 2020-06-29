#include<stdio.h>

long long int matrix[8][8];
int valid[8];

long long int det(int n, int cur) {
    long long int ans = 0;
    int cnt = 0;
    if(cur == 2) {
        long long int two[2][2];
        int first = 1;

        for(int i = 0; i < n; ++i) {
            if(valid[i] == 1) {
                if(first == 1) {
                    first = 0;
                    two[0][0] = matrix[n-cur][i];
                    two[1][0] = matrix[n-cur+1][i];
                }
                else {
                    two[0][1] = matrix[n-cur][i];
                    two[1][1] = matrix[n-cur+1][i];
                }
            }
        }
        ans = two[0][0] * two[1][1] - two[0][1] * two[1][0];
        
        return ans;
    }

    for(int i = 0; i < n; ++i) {
        if(valid[i] == 1) {
            valid[i] = 0;
            if(cnt % 2 == 1) {
                ans -= matrix[n-cur][i] * det(n, cur - 1);    
            }
            else {
                ans += matrix[n-cur][i] * det(n, cur - 1);
            }
            valid[i] = 1;
            cnt++;
        }    
    }

    return ans;
}


int main () {
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        valid[i] = 1;
        for(int j = 0; j < n; ++j) {
            scanf("%lld", &matrix[i][j]);
        }
    }
    long long int ans = det(n, n);
    printf("%lld\n", ans);

    return 0;
}
