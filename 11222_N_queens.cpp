#include <stdio.h>
#include <stdlib.h>
int loc[10]; // array to store each queen's position loc[which row queen's on] = which col queen's on
int n; // the size of the board i.e.how many queens to put
int ans = 0;

// function to check whether this position (queen on row cur, col i) is valid
int valid(int cur, int i) {
    int j;
    for(j = 0;j < cur; j++) { // go through the rows we have already place a queen
        // if there is a queen on the same col or on the same diagonal then it is not valid
        // characteristic of the two diagonals 1. row + col = constant 2. row - col = constant
        if(loc[j] == i || loc[j]-j == i-cur || loc[j]+j == i+cur){
            return 0;
        }
    }
    return 1;
}

//function to find solution of n queens
void place(int cur){ // which row are we placing our queen. cur range from 0 to n - 1

   if(cur == n){ // you find a solution to place n queens
        ans++;
   }
    else { // go through each col to see if there is a valid place to put queen on the board.
        for(int i = 0; i < n; i++) {
            if(valid(cur, i)){ // check if valid
                loc[cur] = i; // if valid then place the queen on row cur, col i
                place(cur + 1); // heading to next row
            }
        }
   }
   return;
}


int main() {

    scanf("%d", &n);
    place(0);
    printf("%d\n", ans);
    return 0;
}
