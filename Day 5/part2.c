#include <stdio.h>

#define DIM 1000

void minmax(int n1, int n2, int *mn, int *mx)
{
	if(n1>n2) {
	*mn = n2;
	*mx = n1;
	}
	else {
		*mn = n1;
		*mx = n2;
	}
}

int main(void) {
	FILE *fp;
	int i,j,x1,y1,x2,y2,min,max,inters;
	int map[DIM][DIM];
	inters = 0;
	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) {
			map[i][j]=0;
		}
	}
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2)>0) {
			if(x1 == x2) {
				minmax(y1, y2, &min, &max);
				for(i=min;i<=max;i++) {
					map[i][x1]++;
					if(map[i][x1]==2) {
						inters++;
					}
				}
			}
			else if(y1 == y2) {
				minmax(x1, x2, &min, &max);
				for(i=min;i<=max;i++) {
					map[y1][i]++;
					if(map[y1][i]==2) {
						inters++;
					}
				}
			}
			else {
				i=x1;
				j=y1;
				while(i!=x2+(1*(x1<x2)-1*(x1>x2))) {
					map[j][i]++;
					if(map[j][i]==2) {
						inters++;
					}
					if(y1<y2)
						j++;
					else
						j--;
					if(x1<x2)
						i++;
					else
						i--;
				}
			}
		}
		fclose(fp);
		fp = NULL;

		printf("Result: %d\n", inters);
	}
	else
		printf("Error opening the file\n");

	return 0;
}
