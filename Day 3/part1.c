#include <stdio.h>
#include <string.h>
#define MAXLEN 100
int main(void) {
	int ndata, gamma, epsilon, i, len, ones;
	char tmp[100];
	FILE *fp;
	
	ndata = 0;
	gamma = 0;
	epsilon = 0;
	i=0;
	fp = fopen("input.txt", "r");
	if(fp) {
		fscanf(fp, "%s", tmp);
		len = strlen(tmp);
		rewind(fp);
		while(fscanf(fp,"%s",tmp)>0) {
			ndata++;
		}
		while(i<len) {
			rewind(fp);
			ones = 0;
			while(fscanf(fp,"%s",tmp)>0) {
				ones+=(tmp[i]-'0');
			}
			gamma *= 2;
			epsilon *= 2;
			if(ones*2>ndata) {
				gamma += 1;
			}
			else {
				epsilon += 1;
			}
			i++;
		}

		printf("Gamma: %d\nEpsilon: %d\nResult: %d\n", gamma, epsilon, gamma*epsilon);
	}
	else
		printf("Error opening the file\n");

	return 0;
}
