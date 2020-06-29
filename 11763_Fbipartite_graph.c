#include <stdio.h>
int graph[1010][1010] = {0}, dot[1010];
void draw(int a, int c, int v);
int flag = 1;

int main(){
    int i, j, k, t, vert, edge, a, b;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d%d", &vert, &edge);
        flag = 1;
        for(j = 0; j < vert; j++){
            dot[j] = 0;
            for(k = 0; k < vert; k++){
                graph[j][k] = 0;
            }
        }
		dot[0] = 1;
        for(j = 0;j < edge; j++){
            scanf("%d%d", &a, &b);
            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }
        for(j = 1; j < vert; j++){
           if(graph[0][j] == 1){
			   draw(j, dot[0], vert);
		   }
            if(flag == 0){
                break;
            }
        }
        if(flag == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }


    return 0;
}


void draw(int a, int c, int v){
    if(flag == 0){
		return;
	}
	if(dot[a] == 0){
		if(c == 1){
			dot[a] = 2;
		}
		else{
			dot[a] = 1;
		}
		for(int i = 0; i < v; i++){
			if(flag == 0){
				break;
			}
			if(graph[a][i] == 1){
				draw(i, dot[a], v);
			}
		}
	}
	else{
		if(dot[a] == c){
			flag = 0;
		}
	}
    return;
}
