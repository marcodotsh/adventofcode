#include <stdio.h>
#include <stdlib.h>

#define N 100

void fill(int r, int c, int mat[][N], int visit[][N], int grps[], int ngrps);

int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(void)
{
	FILE *fp;
	int mat[N][N], visit[N][N], grps[N*N/2], i, j, ngrps;
	for(i=0;i<N*N/2;i++)
		grps[i] = 0;
	ngrps = 0;
	i = 0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%1d", &mat[i/N][i%N]) > 0) {
			visit[i/N][i%N] = 0;
			i++;
		}
		fclose(fp);
		fp = NULL;

		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {
				if(!visit[i][j] && mat[i][j] != 9) {
					fill(i, j, mat, visit, grps, ngrps);
					ngrps++;
				}
			}
		}
		
		qsort(grps, ngrps, sizeof(int), compare);

		printf("Max1: %d\nMax2: %d\nMax3: %d\nResult: %d\n", grps[ngrps-1], grps[ngrps-2], grps[ngrps-3], grps[ngrps-1]*grps[ngrps-2]*grps[ngrps-3]);
		
	}
	else 
		printf("Error opening the file\n");
	
	return 0;
}

void fill(int r, int c, int mat[][N], int visit[][N], int grps[], int ngrps)
{
	if(visit[r][c] || mat[r][c] == 9)
		return;

	visit[r][c] = 1;
	grps[ngrps]++;

	if(r>0) fill(r-1, c, mat, visit, grps, ngrps);
	if(c>0) fill(r, c-1, mat, visit, grps, ngrps);
	if(r<N-1) fill(r+1, c, mat, visit, grps, ngrps);
	if(c<N-1) fill(r, c+1, mat, visit, grps, ngrps);
}
