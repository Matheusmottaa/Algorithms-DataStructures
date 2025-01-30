#include <stdio.h> 
#include <stdlib.h>


typedef struct Node
{
	int data; 
	struct Node* next; 
}Node;

typedef struct Queue
{
	struct Node* first; 
	struct Node* last; 
	int size; 
}Queue;

Queue* createQueue(); 
void enqueue(Queue *, int); 
int dequeue(Queue*); 
int first(Queue*); 
int last(Queue*); 
int isEmpty(const Queue *); 
int isFull(const Queue *); 

int main()
{

	Queue* q = createQueue(); 

	enqueue(q, 3); 
	enqueue(q, 5); 
	enqueue(q, 8); 
	enqueue(q, 12); 

	for (int i = 0; i < 4; ++i)
		printf("%d\n", dequeue(q)); 

	puts("\n"); 

	printf("Is empty? %s\n", (isEmpty(q) ? "Yes" : "No"));


	return 0; 
}

struct Queue* createQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue)); 
	q->first = NULL; 
	q->last = NULL; 
	q->size = 0; 
	return q; 
}

void enqueue(Queue *q, int elem)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	if (temp == NULL)
	{
		fprintf(stderr, "Queue is full!\n"); 
		return; 
	}

	temp->data = elem; 
	temp->next = NULL; 
	if (!q->first)
	{
		q->first = q->last = temp;
		q->size++; 
		return; 
	}
	
	q->last->next = temp; 
	q->last = temp;
	q->size++; 
}

int dequeue(Queue* q)
{
	if (q->first == NULL)
	{
		fprintf(stderr, "Queue is empty!\n"); 
		exit(EXIT_FAILURE); 
	}
	struct Node* r = q->first; 
	int elem = r->data; 
	q->first = q->first->next; 
	q->size--; 
	free(r); 
	return elem; 
}

int first(const Queue *q)
{
	if (q->first == NULL)
	{
		fprintf(stderr, "Queue is empty!\n"); 
		exit(EXIT_FAILURE); 
	}
	return q->first->data; 
}


int last(const Queue* q)
{
	if (q->first == NULL)
	{
		fprintf(stderr, "Queue is empty!\n"); 
		exit(EXIT_FAILURE); 
	}
	return q->last->data; 
}

int isFull(const Queue* q)
{
	Node* temp = (Node*)malloc(sizeof(Node)); 
	if (temp == NULL)
		return 1; 
	free(temp); 
	return 0; 
}

int isEmpty(const Queue* q)
{
	return q->first == NULL; 
}
