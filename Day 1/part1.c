#include <stdio.h>

int main(void) {
    int prev, curr, tot;
    FILE *fp;
    tot=0;

    fp = fopen("input.txt", "r");
    if(fp) {
        fscanf(fp, "%d", &prev);
        while(fscanf(fp, "%d", &curr)>0) {
            if(curr>prev) {
                tot++;
            }
            prev = curr;
        }
        fclose(fp);
        fp = NULL;
        printf("Number of increases: %d\n", tot);
    }
    else {
        printf("Error opening the file\n");
    }

    return 0;
}
