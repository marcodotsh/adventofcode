#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define NC 6

typedef struct N {
	char data;
	struct N* link[DIM];
	struct N* next;
	int isVisited;
	int nLinks;
} node_t;

typedef node_t* Ptr_node;

Ptr_node insertToTail(Ptr_node l, char val);

int found(Ptr_node l, char val);

Ptr_node find(Ptr_node l, char val);

void link(Ptr_node l, char a, char b);

void print(Ptr_node l){
	if(!l)
		return;
	printf("%c\n",l->data);
	print(l->next);
}

int nways(Ptr_node l);

int main(void)
{
	int res;
	char tmp1[NC], tmp2[NC];
	Ptr_node head, t1, t2;
	head = NULL;
	FILE *fp;
	fp = fopen("input.txt", "r");
	head = insertToTail(head, 's');
	if(fp) {
		while(fscanf(fp, " %[^-]-%s", tmp1, tmp2)>0) {
			if(tmp1[0]!='s') {
				if(!found(head,tmp1[0])) {
					head = insertToTail(head,tmp1[0]);
				}
			}
			if(tmp2[0]!='s') {
				if(!found(head,tmp2[0])) {
					head = insertToTail(head,tmp2[0]);
				}
			}
		}
		rewind(fp);
		while(fscanf(fp, " %[^-]-%s", tmp1, tmp2)>0) {
			link(head, tmp1[0], tmp2[0]);
		}
		fclose(fp);
		fp = NULL;

		res = nways(head);
		printf("Number of ways %d\n", res);
	}
	else
		printf("Error opening the file\n");

	return 0;
}

Ptr_node insertToTail(Ptr_node l, char val)
{
	if(!l) {
		int i;
		Ptr_node tmp;
		tmp = malloc(sizeof(node_t));
		if(tmp) {
			tmp->data=val;
			tmp->next = NULL;
			tmp->isVisited = 0;
			tmp->nLinks = 0;
		}
		else
			printf("Memory allocation error\n");
		return tmp;
	}
	l->next = insertToTail(l->next, val);
	return l;	
}

int found(Ptr_node l, char val)
{
	if(!l)
		return 0;
	if(l->data==val)
		return 1;
	return found(l->next,val);
}

Ptr_node find(Ptr_node l, char val)
{
	if(!l)
		return NULL;
	if(l->data==val)
		return l;
	return find(l->next, val);
}

void link(Ptr_node l, char a, char b)
{
	Ptr_node e1, e2;
	e1 = find(l,a);
	e2 = find(l,b);
	e1->link[(e1->nLinks)++]=e2;
	e2->link[(e2->nLinks)++]=e1;
}

int nways(Ptr_node l) {
	if(l->data=='e')
		return 1;
	int i, res;
	res = 0;
	if(l->data>='a'&&l->data<='z') {
		l->isVisited = 1;
	}
	for(i=0;i<l->nLinks;i++) {
		if(!(l->link[i]->isVisited)) {
			res += nways(l->link[i]);
		}
	}

	l->isVisited = 0;

	return res;
}
