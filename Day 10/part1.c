#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char line[102][200], tmp[200], firstwrong[102];
	int i, j, nlines, nwrongs, flag, curs, res;
	nlines = 0;
	nwrongs = 0;
	res = 0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%s", tmp)>0) {
			strcpy(line[nlines++], tmp);
		}

		for(i=0;i<nlines;i++) {
			strcpy(tmp, "\0");
			curs = 0;
			flag = 1;
			for(j=0;line[i][j]!='\0' && flag;j++) {
				if(line[i][j]=='(' || line[i][j]=='[' || line[i][j]=='{' || line[i][j]=='<') {
					tmp[curs++]=line[i][j];
					tmp[curs]='\0';
				}
				else {
					if(tmp[curs-1]==((line[i][j]==')')*(line[i][j]-1)+(line[i][j]!=')')*(line[i][j]-2))) {
						tmp[--curs]='\0';
					}
					else {
						printf("%c is wrong\n", line[i][j]);
						firstwrong[nwrongs++]=line[i][j];
						flag = 0;
					}
				}
			}
		}
		
		for(i=0;i<nwrongs;i++) {
			switch (firstwrong[i]) {
				case ')':
					res += 3;
					break;
				case ']':
					res += 57;
					break;
				case '}':
					res += 1197;
					break;
				case '>':
					res += 25137;
			}
		}

		printf("Result: %d\n", res);

	}
	else {
		printf("Error opening the file\n");
	}

	return 0;
}
