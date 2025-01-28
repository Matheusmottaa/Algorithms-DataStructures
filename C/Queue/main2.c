#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int* data; 
	int roar; 
	int front; 
	int size; 
};


struct Queue* createQueue(int); 
void enqueue(struct Queue*, int); 
int dequeue(struct Queue *); 
int first(const struct Queue *); 
int last(const struct Queue *); 
int isEmpty(const struct Queue *); 
int isFull(const struct Queue *); 

int main()
{
	struct Queue* qv = createQueue(6); 

	enqueue(qv, 1); 
	enqueue(qv, 2);
	enqueue(qv, 3);

	printf("%d\n", dequeue(qv)); 

	return 0; 
}


struct Queue* createQueue(int size)
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->data = (int*)malloc(sizeof(int) * size); 
	q->roar = 0; 
	q->front = 0;
	q->size = size; 
	return q; 
}

void enqueue(struct Queue *q, int elem)
{
	if ((q->roar + 1) % q->size == q->front)
	{
		fprintf(stderr, "Queue is full!\n"); 
		return; 
	}

	q->data[q->roar] = elem; 
	q->roar = (q->roar + 1) % q->size; 
}


int dequeue(struct Queue* q)
{
	if (q->roar == q->front)
	{
		fprintf(stderr, "Empty List\n!"); 
		exit(EXIT_FAILURE); 
	}
	int elem = q->data[q->front];
	q->front = (q->front + 1) % q->size; 
	return elem; 
}

int first(const struct Queue* q)
{
	if (q->roar == q->front)
	{
		fprintf(stderr, "Queue is empty!\n"); 
		exit(EXIT_FAILURE); 
	}
	return q->data[q->front]; 
}

int last(const struct Queue* q)
{
	if (q->roar == q->front)
	{
		fprintf(stderr, "Queue is empty!\n"); 
		exit(EXIT_FAILURE); 
	}

	return q->data[(q->roar-1+q->size)%q->size];
}


int isEmpty(const struct Queue* q)
{
	return q->roar == q->front; 
}

int isFull(const struct Queue* q)
{
	return (q->roar + 1) % q->size == q->front; 
}