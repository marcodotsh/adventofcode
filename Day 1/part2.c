#include <stdio.h>
#define DIM 60
#define NELVES 266

int main(void) {
    FILE * fd;
    char str[DIM];
    int i, j, cal[NELVES] = {0}, calFood, bubble;

    fd = fopen("input.txt", "r");
    if(fd) {
        i = 0;
        while(fgets(str,DIM,fd) != NULL) {
            if(str[0]=='\n') {
                printf("Elf\t%d\nCalories\t%d\n\n", i+1, cal[i]);
                i++;
            }
            else {
                sscanf(str,"%d", &calFood);
                cal[i] += calFood;        
            }
        }
        if(str[0]=='\n') {
            printf("Elf\t%d\nCalories\t%d\n\n", i+1, cal[i]);
        }

        for (i=0;i<3;i++) {
            for(j=0;j<NELVES-1;j++) {
                if(cal[j]>cal[j+1]) {
                    bubble = cal[j];
                    cal[j] = cal[j+1];
                    cal[j+1] = bubble;
                }
            }
        }
        printf("Top three: %d\n", cal[NELVES-1]+cal[NELVES-2]+cal[NELVES-3]);
    }
    else
        printf("Error opening file\n");

    return 0;
}
