#include <stdio.h>
#include <string.h>

#define SEGM 7
#define OUT_DIG 4
#define IN_DIG 10

int isInside(char x[], char s[]);

int anagram(char x[], char s[]);

int main(void)
{		
	char idigit[IN_DIG][SEGM+1], odigit[OUT_DIG][SEGM+1], ddigit[IN_DIG][SEGM+1];
	int res, i, j, sum, num, found;
	FILE *fp;
	res = 0;
	sum = 0;
	num = 0;
	found = 0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s", idigit[0],idigit[1], idigit[2], idigit[3], idigit[4], idigit[5], idigit[6], idigit[7], idigit[8], idigit[9],  odigit[0], odigit[1], odigit[2], odigit[3])>0) {
			for(i=0;i<IN_DIG;i++) {
				if(strlen(idigit[i]) == 2) {
					strcpy(ddigit[1], idigit[i]);
				}
				else if(strlen(idigit[i]) == 4) {
					strcpy(ddigit[4], idigit[i]);
				}
				else if(strlen(idigit[i]) == 3) {
					strcpy(ddigit[7], idigit[i]);
				}
				else if(strlen(idigit[i]) == 7) {
					strcpy(ddigit[8], idigit[i]);
				}
			}
			for(i=0;i<IN_DIG;i++) {
				if(strlen(idigit[i]) == 6) {
					if(isInside(ddigit[4], idigit[i])) {
						strcpy(ddigit[9], idigit[i]);
					}
					else if(isInside(ddigit[7], idigit[i])) {
						strcpy(ddigit[0], idigit[i]);
					}
					else {
						strcpy(ddigit[6], idigit[i]);
					}
				}
			}
			for(i=0;i<IN_DIG;i++) {
				if(strlen(idigit[i]) == 5) {
					if(isInside(ddigit[1], idigit[i])) {
						strcpy(ddigit[3], idigit[i]);
					}
					else if(isInside(idigit[i], ddigit[6])) {
						strcpy(ddigit[5], idigit[i]);
					}
					else {
						strcpy(ddigit[2], idigit[i]);
					}
				}
			}
			
			for(i=0, num=0;i<OUT_DIG;i++) {
				found = 0;
				for(j=0;j<IN_DIG && !found;j++) {
					if(anagram(ddigit[j], odigit[i])) {
						num *= 10;
						num += j;
						found = 1;
					}
				}	
			}
			sum += num;
		}
		fclose(fp);
		fp = NULL;

		printf("Total: %d\n", sum);
	}
	else {
		printf("Error opening the file\n");
	}

	return 0;
}

int isInside(char x[], char s[])
{	
	int res, len1, len2, i, j;
	res = 1;
	len1 = strlen(x);
	len2 = strlen(s);
	for(i=0;i<len1 && res;i++) {
		res = 0;
		for(j=0;j<len2 && !res;j++) {
			if(x[i]==s[j]) {
				res = 1;
			}
		}
	}
	
	return res;
}

int anagram(char x[], char s[])
{	
	int res, len1, len2, i, j;
	res = 1;
	len1 = strlen(x);
	len2 = strlen(s);
	if(len1!=len2)
		res = 0;
	for(i=0;i<len1 && res;i++) {
		res = 0;
		for(j=0;j<len2 && !res;j++) {
			if(x[i]==s[j]) {
				res = 1;
			}
		}
	}
	
	return res;
}
