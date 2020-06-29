#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int order;
    int score;
    char name[25];
}stuid;
stuid qlist[100100];
int cmp(stuid *a, stuid *b);

int main(){
    int n, i, point;
    char temp[25];
    scanf("%d",&n);
    for(i = 0;i < n; i++){
        scanf("%s%d", temp, &point);
        qlist[i].order = i + 1;
        qlist[i].score = point;
        strcpy(qlist[i].name, temp);
    }
    qsort(qlist, n, sizeof(qlist[0]), cmp);
    for(i = 0;i < n; i++){
        printf("%s\n", qlist[i].name);
    }

    return 0;
}


int cmp(stuid *a,stuid *b){
    if(b->score - a->score == 0){
        return a->order -b->order;
    }
    else{
        return b->score - a->score;
    }


}
