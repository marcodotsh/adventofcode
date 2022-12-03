#include <stdio.h>
#define STRDIM 5

int movePts(int opp, int outcome) {
    int pts;

    pts = (opp + outcome - 1) % 3;

    if(pts==0) {
        pts = 3;
    }

    return pts;

}

int calcScore(char opp, char outcome) {
/*
    This time A,B,C are rock, paper, scissors
    X,Y,Z are if we lost, draw, win

    Let's normalize A,B,C to 1,2,3 and X,Y,Z to 0,1,2
    A,B,C -= 64
    X,Y,Z -= 88

    This way X,Y,Z * 3 gives us the points of a l/d/w

    to get the points of the move we use:

    movePts = (opp + outcome) % 3 + 1

*/

    opp -= 64;
    outcome -= 88;

    return movePts(opp, outcome) + ((outcome) * 3);

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