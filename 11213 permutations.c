#include <stdio.h>

char list[10]; // array to store the result of permutation

// functiuon to print the result of permutation
void show(int n)
{
    int i;
    printf("(%c", list[0]);
    for (i = 1; i < n; i++) {
        printf(",%c", list[i]);
    }
    printf(")\n");
}

//function to swap the value of two position
void Swap(int k, int i)
{
    int temp = list[k];
    list[k] = list[i];
    list[i] = temp;
    return;
}

// function to find all possible permutation 
void Perm(int k, int n) // k = current position, n = permutaiton of how many numbers
{
   int i;
   if(k == n - 1){ // you have found a possible permutation
    show(n);
   }
   else{ // swap every element that have not swapped before and move onto next position
     for(i = k; i < n; i++){  
        Swap(k, i); // be caution that swap with itself is also a way to swap
        Perm(k + 1, n); 
        Swap(i, k); // remember to swap the elements back
     }
   }
   return;
}

int main(void)
{
    int num, i;

    scanf("%d", &num);

    for(i = 0; i < num; i++)
        list[i] = '1' + i;
    Perm(0, num); // start form the first position (index = 0)

    return 0;
}
