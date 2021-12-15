#include <stdio.h>

#define N 10
#define DAYS 100

void resetFlashes(int a[][N], int n);

void flash(int r, int c, int squid[][N], int hasShone[][N], int n);

int main(void)
{
	int squid[N][N], hasShone[N][N];
	FILE *fp;
	int i, j, k, nflsh;
	i = 0;
	nflsh = 0;
	resetFlashes(hasShone, N);
	fp = fopen("input.txt", "r"); 
	if(fp){
		while(fscanf(fp, "%1d", &squid[i/N][i%N])>0) {
			i++;
		}
		fclose(fp);
		fp = NULL;
		for(i=0;i<DAYS;i++) {
			for(j=0;j<N;j++) {
				for(k=0;k<N;k++) {
					squid[j][k]++;
				}
			}
			for(j=0;j<N;j++) {
				for(k=0;k<N;k++) {
					if(!hasShone[j][k] && squid[j][k]>9) {
						flash(j,k,squid,hasShone,N);
					}
				}
			}
			for(j=0;j<N;j++) {
				for(k=0;k<N;k++) {
					if(hasShone[j][k]) {
						nflsh++;
						squid[j][k] = 0;
						hasShone[j][k] = 0;
					}
				}
			}
		}

		printf("Number of flashes: %d\n", nflsh);
	}
	else
		printf("Error opening the file\n");

	return 0;
}

void resetFlashes(int a[][N], int n)
{
	int i, j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			a[i][j] = 0;
		}
	}
}

void flash(int r, int c, int squid[][N], int hasShone[][N], int n)
{
	if(hasShone[r][c])
		return;
	
	hasShone[r][c] = 1;

	if(r>0) {
		squid[r-1][c]++;
		if(squid[r-1][c]>9) {
			flash(r-1,c,squid,hasShone,n);
		}
	}
	if(c>0) {
		squid[r][c-1]++;
		if(squid[r][c-1]>9) {
			flash(r,c-1,squid,hasShone,n);
		}
	}
	if(r<n-1) {
		squid[r+1][c]++;
		if(squid[r+1][c]>9) {
			flash(r+1,c,squid,hasShone,n);
		}
	}
	if(c<n-1) {
		squid[r][c+1]++;
		if(squid[r][c+1]>9) {
			flash(r,c+1,squid,hasShone,n);
		}
	}
	if(r>0 && c>0) {
		squid[r-1][c-1]++;
		if(squid[r-1][c-1]>9) {
			flash(r-1,c-1,squid,hasShone,n);
		}
	}
	if(r>0 && c<n-1) {
		squid[r-1][c+1]++;
		if(squid[r-1][c+1]>9) {
			flash(r-1,c+1,squid,hasShone,n);
		}
	}
	if(r<n-1 && c>0) {
		squid[r+1][c-1]++;
		if(squid[r+1][c-1]>9) {
			flash(r+1,c-1,squid,hasShone,n);
		}
	}
	if(r<n-1 && c<n-1) {
		squid[r+1][c+1]++;
		if(squid[r+1][c+1]>9) {
			flash(r+1,c+1,squid,hasShone,n);
		}
	}
}
