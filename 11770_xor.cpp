#include <stdio.h>
int times[30]={0};
long long int numbers[100100];

int main(){
    int n;
    long long int num, k = 0, sum = 0;
    scanf("%d",&n);
    for(int i = 0;i < 30; i++){
        times[i] = -(n/2);
    }

    for(int j = 0;j < n;j++){
        scanf("%lld",&num);
        numbers[j] = num;
        int i = 0;
        do{
            times[i] += num % 2;
            i++;
        }while(num /= 2);
    }
    /*for(i = 0;i < 30;i++){
        printf("%d",times[i]);
    }*/
    for(int i = 29;i > -1; i--){
        if(times[i] > 0){
            k = k*2 + 1;
        }
        else{
            k = k*2;
        }
    }
    for(int i = 0 ; i < n ; i++){
        sum += (numbers[i] ^ k);
    }
    printf("%lld\n",sum);

    return 0;
}
