#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node
{
	int data;
	struct _double_node *prev;
	struct _double_node *next;
} double_node;

void init(double_node *phead)
{
	phead->prev = phead;
	phead->next = phead;
}

void insert_dnode(double_node *before, int data)
{
	double_node *newnode = (double_node *)malloc(sizeof(double_node));
	newnode->data = data;
	newnode->prev = before;
	newnode->next = before->next;
	before->next->prev = newnode;
	before->next = newnode;
}

void delete_dnode(double_node *head, double_node *removed)
{
	if(removed == head) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}

void print_all(double_node *phead)
{
	double_node *p;
	for(p = phead->next; p != phead; p = p->next)
		printf(" <- %d -> ", p->data);
	printf("\n");
}

int main(void)
{
	double_node *head =(double_node *)malloc(sizeof(double_node));	
	init(head);
	printf("insert nodes after the head node \n");
	for(int i = 0; i < 5; i++)
	{
		insert_dnode(head, i);
		print_all(head);
	}
	printf("\n nodes are delted \n");
	for(int i = 0; i < 5; i++)
	{
		print_all(head);
		delete_dnode(head, head->next);
	}
	free(head);
	return 0;
}
