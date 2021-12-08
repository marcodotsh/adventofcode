#include <stdio.h>
#include <stdlib.h>

#define DIM 5
#define N_BOARDS 100

typedef struct N {
	int data;
	struct N* next;
} node_t;

typedef node_t* Ptr_node;

typedef struct {
	int val[DIM][DIM];
	int rows[DIM];
	int cols[DIM];
	int sum;
} board_t;

Ptr_node insertToTail(Ptr_node l, int val);

int main(void) {
	FILE *fp;
	Ptr_node head, tp;
	board_t boards[N_BOARDS];
	int num, i, j, k, tmp, winner, winnum;
	winner = -1;
	winnum = -1;
	num = 0;
	head = NULL;
	tp = NULL;
	fp = fopen("input.txt", "r");
	if(fp) {
		fscanf(fp, "%d", &tmp);
		head = insertToTail(head, tmp);
		while(fscanf(fp, ",%d", &tmp)>0) {
			insertToTail(head, tmp);
		}
		while(fscanf(fp, "%d %d %d %d %d", &boards[num/5].val[num%5][0], &boards[num/5].val[num%5][1], &boards[num/5].val[num%5][2], &boards[num/5].val[num%5][3], &boards[num/5].val[num%5][4])>0) {
			num++;
		}
		num /= 5;
		for(i=0;i<num;i++) {
			boards[i].sum = 0;
			for(j=0;j<DIM;j++) {
				boards[i].rows[j] = 0;
				boards[i].cols[j] = 0;
				for(k=0;k<DIM;k++) {
					boards[i].sum += boards[i].val[j][k];
				}
			}
		}
		fclose(fp);
		fp = NULL;

		while(head && winner == -1) {
			tmp = head->data;

			for(i=0;i<num && winner == -1;i++) {
				for(j=0;j<DIM && winner == -1;j++) {
					for(k=0;k<DIM && winner == -1;k++) {
						if(boards[i].val[j][k]==tmp) {
							boards[i].rows[j]++;
							boards[i].cols[k]++;
							boards[i].sum -= boards[i].val[j][k];
							if(boards[i].rows[j]==5 || boards[i].cols[j]==5) {
								winner = i;
								winnum = head->data;
							}
						}
					}
				}
			}
			tp = head;
			head = head->next;
			free(tp);
			tp = NULL;
		}

		printf("Winner: %d\nSum of unmarked: %d\nLast called: %d\nProduct: %d\n", winner, boards[winner].sum, winnum, boards[winner].sum * winnum);
	}
	else
		printf("Error opening the file\n");

	return 0;
}

Ptr_node insertToTail(Ptr_node l, int val)
{
	if(!l) {
		Ptr_node tmp;
		tmp = malloc(sizeof(node_t));
		tmp->data=val;
		tmp->next=NULL;
		l=tmp;
		return l;		
	}
	l->next = insertToTail(l->next, val);
	return l;
}
