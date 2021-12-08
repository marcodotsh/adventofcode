#include <stdio.h>
#include <stdlib.h>

#define DIM 1000

int abs(int n);

int compare(const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b);
}

int main(void) {
	int i, crabs[DIM], len, med, fuel, center;
	FILE *fp;
	len = 0;
	fuel = 0;
	fp = fopen("input.txt","r");
	if(fp) {
		while(fscanf(fp, "%d,", &crabs[len])>0) {
			len++;
		}
		
		qsort(crabs, len, sizeof(int), compare);
		
		center = crabs[len/2];
		for(i=0;i<len;i++) {
			fuel += abs(crabs[i]-center);
		}

		printf("Position: %d\nFuel needed: %d\n", med, fuel);

	}
	else
		printf("Error opening the file\n");
	return 0;
}

int abs(int n)
{
	if(n>0)
		return n;
	return -n;
}
