#include <stdio.h>
#define STRDIM 5

int roundOutcome(int sub) {
    
    return (sub % 3) * 3;

}

int calcScore(char opp, char me) {
/*
    We will use the difference bw the letters:
    Let's normalize A,B,C to -3,-2,-1 and X,Y,Z to 1,2,3
    A,B,C -= 68
    X,Y,Z -= 87

    Let's start with draw:
    rock vs rock:           (int) (X - A) == 4
    paper vs paper:         (int) (Y - B) == 4
    scissors vs scissors:   (int) (Z - C) == 4

    Now let's look at win:
    rock vs paper:          (int) (Y - A) == 5
    paper vs scissors:      (int) (Z - B) == 5
    scissors vs rock:       (int) (X - C) == 2

    At last, lost:
    rock vs scissors:       (int) (Z - A) == 6
    paper vs rock:          (int) (X - B) == 3
    scissors vs paper:      (int) (Y - C) == 3

    We see that if we consider the class of mod 3 we have:
    [0]: lost
    [1]: draw
    [2]: win

    and if we multiply by three we get exactly the point from l/d/w

*/

    opp -= 68;
    me -= 87;

    return roundOutcome(me - opp) + me;

}

int main(void) {

    int totScore;
    FILE * fd;
    char str[STRDIM];
    char c1, c2; /**two chars to grab the letters in each line*/

    totScore = 0;

    fd = fopen("input.txt", "r");

    if(fd == NULL) {

        printf("Error opening file\n");

        return -1;

    }

    while(fgets(str, STRDIM, fd) != NULL) {

        sscanf(str, "%c %c", &c1, &c2);
        totScore += calcScore(c1, c2);

    }

    printf("Total score: %d\n", totScore);

    return 0;

}