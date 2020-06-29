#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name[25];
    int profita;
    int profitb;
}factory;

int cmpp(factory *a,factory *b);
int cmpl(factory *a,factory *b);
int cmpa(factory *a,factory *b);

int main(){
    int i, n, x, y;
    int flag = 0;
    factory listof[500], finall[500];
    scanf("%d%d%d", &n, &x, &y);
    for(i = 0;i < n; i++){
        scanf("%s%d%d", listof[i].name, &listof[i].profita, &listof[i].profitb);
    }
    qsort(listof, n, sizeof(listof[0]), cmpp);
    qsort(listof + y, n - y, sizeof(listof[y]), cmpa);
    for(i = 0;i < x; i++){
        finall[i] = listof[y+i];
        //printf("%s\n",finall[i].name);
    }
    qsort(finall, x, sizeof(finall[0]), cmpl);
    for(i = 0;i < x; i++){
        printf("%s\n", finall[i].name);
    }

    return 0;
}


int cmpp(factory *a,factory *b){
    if((*b).profitb-(*b).profita - ((*a).profitb-(*a).profita) == 0){
        return (*a).profita - (*b).profita;
    }
    return (*b).profitb-(*b).profita - ((*a).profitb-(*a).profita);
}


int cmpl(factory *a,factory *b){
    int i;
    for(i = 0;i < 25; i++){
        if(a->name[i] - b->name[i] != 0){
            break;
        }
    }
    return a->name[i] - b->name[i];
}


int cmpa(factory *a,factory *b){

    return (*b).profita - (*a).profita;
}
