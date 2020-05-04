#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int j, k, len, count;
    char s[2001];

    while(scanf("%s",s) != EOF){
        len = strlen(s);
        count = 0;
        for(j = 0; j < len; j++){ // suppose the middle of the exquisite string is j
            for(k = 1; j - k >= 0 && j + k < len; k++){ // suppose the length of the exquisite string is odd
                if(s[j - k] == s[j + k]){
                    count++;
                }
                else{
                    break;
                }
            }
             for(k = 0;j - k >= 0 && j + k < len; k++){ // suppose the length of the exquisite string is even
               if(s[j - k] == s[j + 1 + k]){
                    count++;
               }
               else{
                    break;
               }
            }
        }
       printf("%d\n", count);
    }
    return 0;
}
