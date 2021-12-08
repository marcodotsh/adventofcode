#include <stdio.h>
#include <string.h>

int main(void)
{
	int depth, horiz, aim, temp;
	char str[8];
	FILE *fp;
	depth=0;
	horiz=0;
	aim=0;
	fp = fopen("input.txt", "r");
	if(fp) {
		while(fscanf(fp, "%s %d", str, &temp)>0) {
			if(strcmp(str, "forward")==0) {
				horiz += temp;
				depth += (aim*temp);
			}
			else if(strcmp(str, "down")==0)
				aim += temp;
			else
				aim -= temp;
		}
		fclose(fp);
		fp=NULL;
		
		printf("Horizontal position: %d\nDepth: %d\nProduct: %d\n", horiz, depth, horiz*depth);

	}
	else
		printf("Error opening the file\n");

	return 0;
}
