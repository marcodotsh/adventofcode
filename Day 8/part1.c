#include <stdio.h>
#include <string.h>

#define SEGM 7
#define OUT_DIG 4
#define IN_DIG 10

int main(void)
{	
	char idigit[IN_DIG][SEGM+1], odigit[OUT_DIG][SEGM+1];
	int res, i;
	FILE *fp;
	res = 0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s", idigit[0],idigit[1], idigit[2], idigit[3], idigit[4], idigit[5], idigit[6], idigit[7], idigit[8], idigit[9],  odigit[0], odigit[1], odigit[2], odigit[3])>0) {
			for(i=0;i<OUT_DIG;i++) {
				if(strlen(odigit[i]) == 2 || strlen(odigit[i]) == 4 || strlen(odigit[i]) == 3 || strlen(odigit[i]) == 7) {
					res++;
				}
			}
		}
		fclose(fp);
		fp = NULL;
		printf("Number of 1,4,7,8s: %d\n", res);
	}
	else {
		printf("Error opening the file\n");
	}

	return 0;
}
