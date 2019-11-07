#include <stdio.h>
#include <stdlib.h>

char instr[1001];

int app1(int i, int j);
int app(int i, int j);

// with dynamic programming

// array for dynamic programming (storing minimum deletion of a subsequence to become palindrome)
int min_step[1001][1001]; // min_step[i][j] = min_deletion of subsequence (i, j)


//return the minimum deletion to make a palindrome sequence for index i to j.
int app(int i, int j) {
    int del;
    if(min_step[i][j] != -1) { // you don't need to delete any thing
        return min_step[i][j];
    }
    if(instr[i] == instr[j]) {
        if(i + 1 == j || i + 2 == j) {
            min_step[i][j] = 0;
            return 0;
        }
        del = app(i + 1, j - 1);
        min_step[i][j] = del;
    }
    else { // you should delete either most right element or most left element
        if(i + 1 == j) {
            min_step[i][j] = 1;
            return 1;
        }
        del = app(i + 1, j); // imagine you delete index i so you move onto subsequence (i+1, j)
        min_step[i][j] = del + 1;
        del = app(i, j - 1); // imagine you delete index j so you move onto subsequence (i, j-1)
        if(min_step[i][j] > del + 1) {
            min_step[i][j] = del + 1;
        }
    }
    return min_step[i][j];
}

int main() {
    int len, k, min_del;
    scanf("%d %d", &len, &k);
    scanf("%s", instr);

    //initialize array for dp
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len; ++j) {
            min_step[i][j] = -1;
        }
    }

    min_del = app(0, len - 1);
    if(k >= min_del) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }


    return 0;
}


//without dynamic programming
//return the minimum deletion to make a palindrome sequence for index i to j.
int app1(int i, int j) {
    int del1, del2;
    if(instr[i] == instr[j]) { // you don't need to delete any thing
        if(i + 1 == j || i + 2 == j) { //basis
            return 0;
        }
        del1 = app(i + 1, j - 1);
    }
    else { // you should delete either most right element or most left element
        if(i + 1 == j) { // basis
            return 1;
        }
        del1 = app(i + 1, j); // imagine you delete index i so you move onto subsequence (i+1, j)
        del2 = app(i, j - 1); // imagine you delete index j so you move onto subsequence (i, j-1)
        if(del1 > del2) {
            del1 = del2;
        }
        del1 += 1; // remember to plus the element you delete.
    }

    return del1;
}

