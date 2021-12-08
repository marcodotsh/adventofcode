#include <stdio.h>
#include <stdlib.h>

#define N_DAYS 80

int main(void)
{
	FILE *fp;
	int i, j, nfish[9], tmp, tot;
	tot = 0;
	for(i=0;i<9;i++) {
		nfish[i]=0;
	}
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%d,", &tmp)>0) {
			nfish[tmp]++;
		}
		fclose(fp);
		fp = NULL;

		for(i=0;i<N_DAYS;i++) {
			tmp = nfish[0];
			for(j=1;j<=8;j++) {
				nfish[j-1] = nfish[j];
			}
			nfish[8] = tmp;
			nfish[6] += tmp;

		}
		
		for(i=0;i<9;i++) {
			tot += nfish[i];
		}
	
		printf("Number of fishes: %d\n", tot);
	}
	else
		printf("Error opening the file\n");

	return 0;
}
