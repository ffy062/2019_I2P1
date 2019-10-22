#include <stdio.h>
#include <string.h>

int main(){
	int row, col, times;
	char in[105][105];

	scanf("%d %d %d", &row, &col, &times);
	int i, j;
	for(i = 0; i < row; i++)
		scanf("%s", in[i]);

	while(times--){
		for(i = 0; i < row; i++){
			for(j = 0; j < col; j++){
				if(in[i][j] == 'F'){
					if(in[i+1][j] != '#' && in[i+1][j] != 'F' && i < row - 1 )
                        in[i+1][j] = '1';
					if(in[i-1][j] != '#' && in[i-1][j] != 'F' && i > 0)
                        in[i-1][j] = '1';
					if(in[i][j+1] != '#' && in[i][j+1] != 'F' && j < col - 1)
                        in[i][j+1] = '1';
					if(in[i][j-1] != '#' && in[i][j-1] != 'F' && j > 0)
                        in[i][j-1] = '1';
				}
			}
		}
		for(i = 0; i < row; i++){
			for(j = 0; j < col; j++){
				if(in[i][j] == '1')
					in[i][j] = 'F';
			}
		}
	}

	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%c", in[i][j]);
		}
		printf("\n");
	}

	return 0;
}
