#include <stdio.h>
//#include <bits/stdc++.h>

#define m 10177 // the number you want to modulo with

// forward declaration
int mod(int b, int sp, int d); 
int fast_pow_r(int base, int exp);
int fast_pow_l(int base, int exp); 

int main() {
    int b, sp, d;
    while(scanf("%d %d %d", &b, &sp, &d) != EOF) { //you may encounter multiple testcases
        int ans = mod(b, sp, d);
        printf("%d\n", ans);
    } 
    return 0;
}

// function to calculate the answer b = the initial number of bacteria, sp = the new born speed, d = how many days after
//after examination you may conclude the number of bacteria in day d is (b * (sp + 1)^(day - 1))
int mod(int b, int sp, int d) {
    int ans = 1;
    int base = (sp + 1);
    int exp = d - 1;
    // we can use either loop or recursive to calculate (base^exp) % m
    //ans = fast_pow_l(base, exp);
    ans = fast_pow_r(base, exp);
    return(ans * b) % m; // remember to mod 10177 at the end
}

//fast way to calculate (base^exp) % m recursively
int fast_pow_r(int base, int exp){
    if(exp == 0){ // basis
        return 1; // base^0 = 1
    }
    else{ 
        int k = fast_pow_r(base, exp / 2);
        if(exp % 2) // if exp is odd:
            return ((k * k) % m * base) % m; // (((base^exp/2) % m * (base^exp/2) % m) % m * base) % m
        else // if exp is even:
            return (k * k) % m; // (base^exp) % m = ((base^exp/2) % m * (base^exp/2) % m) % m
    }
}


//fast way to calculate (base^exp) % m using loop
int fast_pow_l(int base, int exp) {
     int ans = 1;
     while(exp) {
        if(exp % 2) { // if exp is odd
            ans = (ans * base) % m; 
        }
        base = (base * base) % m;
        exp /= 2;
    }
    return ans;
}

