#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmpa(const Grade *a,const Grade *b);
int cmpd(const Grade *a,const Grade *b);

void sortGrade(Grade *gList, int n, char *order){
    char ch=*order;
    for(int i = 0;i < n;i++){
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    }
    if(ch == 'a'){
        qsort( gList, n, sizeof(gList[0]) , cmpa);
    }
    else{
        qsort( gList, n, sizeof(gList[0]) , cmpd);
    }

    return;
}

int cmpa(const Grade *a,const Grade *b){
    if((*a).total - (*b).total == 0){
        if((*a).Chinese - (*b).Chinese == 0){
            if((*a).English - (*b).English == 0){
                if((*a).math - (*b).math == 0){
                    if((*a).science - (*b).science == 0){
                        return (*a).ID - (*b).ID;
                    }
                    else{
                        return (*a).science - (*b).science;
                    }
                }
                else{
                    return (*a).math - (*b).math;
                }
            }
            else{
                return (*a).English - (*b).English;
            }
        }
        else{
            return (*a).Chinese - (*b).Chinese;
        }
    }
    else{
        return (*a).total - (*b).total;
    }

    return;
}


int cmpd(const Grade *a,const Grade *b){
    if((*a).total - (*b).total == 0){
        if((*a).Chinese - (*b).Chinese == 0){
            if((*a).English - (*b).English == 0){
                if((*a).math - (*b).math == 0){
                    if((*a).science - (*b).science == 0){
                        return (*a).ID - (*b).ID;
                    }
                    else{
                        return -((*a).science - (*b).science);
                    }
                }
                else{
                    return -((*a).math - (*b).math);
                }
            }
            else{
                return -((*a).English - (*b).English);
            }
        }
        else{
            return -((*a).Chinese - (*b).Chinese);
        }
    }
    else{
        return -((*a).total - (*b).total);
    }

    return;

}
