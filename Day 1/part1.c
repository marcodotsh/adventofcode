#include <stdio.h>
#define DIM 60

int main(void) {
    FILE * fd;
    char str[DIM];
    int i, eMax, calTot, calFood, calMax;

    fd = fopen("input.txt", "r");
    if(fd) {
        i = 1;
        calTot = 0;
        calMax = 0;
        while(fgets(str,DIM,fd) != NULL) {
            if(str[0]=='\n') {
                if(calTot>calMax) {
                    calMax = calTot;
                    eMax = i;
                }
                printf("Elf\t%d\nCalories\t%d\n\n", i++, calTot);
                calTot = 0;
            }
            else {
                sscanf(str,"%d", &calFood);
                calTot += calFood;        
            }
        }
        if(str[0]=='\n') {
            if(calTot>calMax) {
                eMax = i;
            }
            printf("Elf\t%d\nCalories\t%d\n\n", i, calTot);
        }
        printf("The elf with the most calories is %d\n", eMax);
    }
    else
        printf("Error opening file\n");

    return 0;
}
