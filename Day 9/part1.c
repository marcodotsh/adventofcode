#include <stdio.h>

#define N 100

int main(void)
{
	FILE *fp;
	int mat[N][N], i, j, risk;
	i = 0;
	risk = 0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%1d", &mat[i/N][i%N])>0) {
			i++;
		}
		fclose(fp);
		fp = NULL;

		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {
				if((j==N-1 || mat[i][j]<mat[i][j+1]) && (i==N-1 || mat[i][j]<mat[i+1][j]) && (j==0 || mat[i][j]<mat[i][j-1]) && (i==0 || mat[i][j]<mat[i-1][j])) {
					risk += (1+mat[i][j]);
				}
			}
		}

		printf("Risk level: %d\n", risk);
	}
	else 
		printf("Error opening the file\n");
	
	return 0;
}
