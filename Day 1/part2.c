#include <stdio.h>

int main(void) {
    int n1, n2, n3, prevtot, tot, num;
    FILE *fp;
    prevtot=0;
	tot=0;
	num=0;

    fp = fopen("input.txt", "r");
    if(fp) {
        fscanf(fp, "%d", &n1);
		fscanf(fp, "%d", &n2);
		fscanf(fp, "%d", &n3);
		prevtot=n1+n2+n3;
		
		n1=n2;
		n2=n3;

        while(fscanf(fp, "%d", &n3)>0) {
            tot = n1+n2+n3;
			if(tot>prevtot) {
                num++;
            }
            n1=n2;
			n2=n3;
			prevtot=tot;
        }
        fclose(fp);
        fp = NULL;
        printf("Number of increases: %d\n", num);
    }
    else {
        printf("Error opening the file\n");
    }

    return 0;
}
