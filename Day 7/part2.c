#include <stdio.h>
#include <stdlib.h>

#define DIM 1000

int abs(int n);

int sumof(int n);

int main(void) {
	int i, crabs[DIM], len, avg, fuel1, fuel2, fuel3, center1, center2;
	FILE *fp;
	len = 0;
	avg = 0;
	fuel1 = 0;
	fuel2 = 0;
	fp = fopen("input.txt","r");
	if(fp) {
		while(fscanf(fp, "%d,", &crabs[len])>0) {
			len++;
		}
		
		for(i=0;i<len;i++) {
			avg += crabs[i];
		}
		avg /= len;
		
		center1 = avg;
		center2 = avg+1;
		for(i=0;i<len;i++) {
			fuel1 += sumof(abs(crabs[i]-center1));
			fuel2 += sumof(abs(crabs[i]-center2));
		}
		
		if(fuel1<fuel2) {
			printf("Position: %d\nFuel needed: %d\n", avg, fuel1);
		}
		else {
			printf("Position: %d\nFuel needed: %d\n", avg+1, fuel2);
		}
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

int sumof(int n)
{
	return (n*(n+1)/2);
}
