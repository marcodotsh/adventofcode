#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

typedef struct N {
	char dato[MAXLEN+1];
	struct N *next;
} nodo_t;

typedef nodo_t* Ptr_nodo;

Ptr_nodo addToHead(Ptr_nodo l, char tmp[]);

int mostfrequent(Ptr_nodo l, int pos);

Ptr_nodo filterList(Ptr_nodo l, int pos, int val);

int main(void) {
	FILE *fp;
	int len, oxy, co2, i, mstfrq, lstfrq;
	char tmp[MAXLEN+1];
	Ptr_nodo head1, head2;
	head1 = NULL;
	head2 = NULL;
	oxy = 0;
	co2 = 0;
	i = 0;
	len = 0;
	fp=fopen("input.txt", "r");
	if(fp) {
		fscanf(fp, "%s", tmp);
		len = strlen(tmp);
		rewind(fp);
		while(fscanf(fp, "%s", tmp)>0) {
			head1 = addToHead(head1, tmp);
			head2 = addToHead(head2, tmp);
		}
		fclose(fp);
		fp = NULL;
	}
	else
		printf("Error opening the file\n");

	while(i<len) {
		mstfrq = mostfrequent(head1, i);
		lstfrq = !mostfrequent(head2, i);
		printf("i=%d\n mstfrq: %d\nlstfrq: %d\n", i, mstfrq, lstfrq);
		head1 = filterList(head1,i,mstfrq);
		head2 = filterList(head2,i,lstfrq);
		
		printf("head1->dato: %s\nhead2->dato: %s\n", head1->dato, head2->dato);

		i++;
	}

	for(i=0;i<len;i++) {
		oxy *= 2;
		co2 *= 2;
		oxy += ((head1->dato)[i]-'0');
		co2 += ((head2->dato)[i]-'0');
	}

	printf("Oxygen generator rating: %d\nCO2 scrubber rating: %d\nLife support rating: %d\n", oxy, co2, oxy*co2);

	return 0;
}

Ptr_nodo addToHead(Ptr_nodo l, char tmp[])
{
	Ptr_nodo p;
	p = malloc(sizeof(nodo_t));
	if(tmp) {
		strcpy(p->dato, tmp);
		p->next = l;
		l=p;
	}
	else
		printf("Error memory allocation\n");

	return l;	
}

int mostfrequent(Ptr_nodo l, int pos) {
	int lines, ones;
	lines = 0;
	ones = 0;
	while(l) {
		lines++;
		ones += ((l->dato)[pos] - '0');
		l = l->next;
	}

	return (2*ones>=lines);
}

Ptr_nodo filterList(Ptr_nodo l, int pos, int val)
{
	Ptr_nodo prev, curr, tmp;
	curr = l;
	prev = NULL;
	
	if(l->next==NULL)
		return l;

	while(curr) {
		if(((curr->dato)[pos]-'0')!=val) {
			tmp = curr;
			curr = curr->next;
			if(prev !=NULL) {
				prev->next = curr;
			}
			else{
				l = curr;
			}
			free(tmp);
			tmp = NULL;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	return l;
}

