#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;
    node* f = NULL;
    node* r = NULL;
void QueueTraversal(node* f)
{
	node* ptr = f;
	printf("Printing the Linkedlist\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
}

void enqueue(int value)
{
	node* newNode = (node*) malloc(sizeof(node));
	if(newNode == NULL) //checking heap is full or not
		printf("Queue is full\n");
	else if(f == NULL && r==NULL) //in case of empty Queue
		{
            newNode->data = value;
		    newNode->next = NULL;
			f= newNode;
			r = newNode;
		}
	else
		{
            newNode->data = value;
		    newNode->next = NULL;
			r->next = newNode;
			r = newNode;
		}
}


int dequeue()
{
	int a = -1;
	node* ptr = f;
	if(f==NULL && r ==NULL)
		printf("Queue is empty\n");
	else{
		f = f->next;
		a = ptr->data;
		free(ptr);
	}
	return a;
}

int main()
{

	enqueue(4);
	enqueue(8);
	enqueue(10);
	enqueue(15);

	int x = dequeue();
	int y = dequeue();
	printf("%d is dequed\n",x );
	printf("%d is dequed\n",y );
	QueueTraversal(f);
}