#include <stdio.h>
char map[1010][1010];
int m, n;
int find(){
    int ans = 0, i, j;
    for(i = 1;i < m + 1; i++){
        for(j = 1;j < n + 1; j++){
            if(map[i][j] == '~'){
                ans++;
                size(i, j);
            }
        }
    }

    return ans;
}
void size(int r,int c){
    
    if(map[r][c] == '~'){
        map[r][c] = 0;
        size(r - 1, c);
        size(r + 1, c);
        size(r ,c + 1);
        size(r ,c - 1);
    }
    else{
        return;
    }
}

int main(){
    int i, j;
    char ch;
    scanf("%d%d", &m, &n);
    for(i = 1;i < m + 1; i++){
        ch = getchar();
        for(j = 1;j <n + 1; j++){
            scanf("%c", &map[i][j]);
        }
    }
    printf("%d\n", find());

    return 0;
}
