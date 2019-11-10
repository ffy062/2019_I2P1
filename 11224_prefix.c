#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


 float oper(){
    char ch;
    float left, right, ans;
    while(isspace(ch = getchar())){
        continue;
    }
    if(ch == '+'){
        printf("( ");
        left = oper();
        printf("+ ");
        right = oper();
        printf(") ");
        ans = left + right;
    }
    else if(ch == '-'){
        printf("( ");
        left = oper();
        printf("- ");
        right = oper();
        printf(") ");
        ans = left - right;
    }
    else if(ch == '*'){
        printf("( ");
        left = oper();
        printf("* ");
        right = oper();
        printf(") ");
        ans = left * right;
    }
    else if(ch == '/'){
        printf("( ");
        left = oper();
        printf("/ ");
        right = oper();
        printf(") ");
        ans = left / right;
    }
    else{
        ans = ch - '0';
        printf("%.0f ", ans);
    }

    return ans;
 }

int main()
{
    int t, i, com;
    float ans;
    scanf("%d", &t);
    for(i = 0;i < t; i++){
        ans = oper();
        com = ans;
        // determine whether ans is a integer.
        if(com == ans){
            printf("= %d\n",com);
        }
        else{
            printf("= %.1f\n",ans);
        }
    }
    return 0;
}
