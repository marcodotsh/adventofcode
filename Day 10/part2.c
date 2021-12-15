#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char line[102][200], tmp[200];
	int i, j, k, nlines, nconts, flag, curs;
	long int contest[102], temp, res;
	nlines = 0;
	nconts = 0;
	res = 0;
	for(i=0;i<102;i++) {
		contest[i] = 0;
	}
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
						flag = 0;
					}
				}
			}
			for(k=curs-1;k>=0 && flag;k--) {
				contest[nconts] *= 5;
				switch (tmp[k]) {
					case '(':
						contest[nconts] += 1;
						break;
					case '[':
						contest[nconts]  += 2;
						break;
					case '{':
						contest[nconts]  += 3;
						break;
					case '<':
						contest[nconts]  += 4;
				}
			}
			nconts += flag;
		}
		
		for(i=0;i<nconts;i++) {
			for(j=0;j<nconts-1;j++) {
				if(contest[j]>contest[j+1]) {
					temp = contest[j];
					contest[j] = contest[j+1];
					contest[j+1] = temp;
				}
			}
		}

		res = contest[nconts/2];

		printf("Result: %ld\n", res);

	}
	else {
		printf("Error opening the file\n");
	}

	return 0;
}
