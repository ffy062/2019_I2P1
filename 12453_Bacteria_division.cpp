#include <stdio.h>
//#include <bits/stdc++.h>

#define m 10177

int mod(int b, int sp, int day);

int main() {
    int b, sp, day;
    while(scanf("%d %d %d", &b, &sp, &day) != EOF) {
        int ans = mod(b, sp, day);
        printf("%d\n", ans);
    } 
    return 0;
}

int mod(int b, int sp, int day) {
    int ans = 1;
    int base = (sp + 1);
    int exp = day - 1;
    while(exp) {
        if(exp % 2) {
            ans = (ans * base) % m; 
        }
        base = (base * base) % m;
        exp /= 2;
    }
    return(ans * b) % m;
}

