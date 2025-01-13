#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}*head = NULL; 

void createListFromArray(const int*, size_t); 
size_t size(); 
void display(); 
void insertAt(int, int); 
int deleteAt(int); 
void reverse(); 

int main()
{

	int a[SIZE] = { 2,3,4,5,6,7 };

	createListFromArray(a, SIZE); 
	insertAt(4, 12); 
	display(); 
	printf("Size of the list: %d\n", size()); 

	puts(""); 

	int position = 5; 
	printf("Delete an element at position %d:  %d\n", position, deleteAt(position)); 
	display(); 
	printf("Size of the list: %d\n", size()); 

	puts("\n"); 

	reverse(); 
	display(); 

	return 0; 
}



void createListFromArray(const int* a, size_t length)
{
	if (length > 0)
	{
		head = (struct Node*)malloc(sizeof(struct Node)); 
		head->data = a[0]; 
		head->next = NULL; 
		head->prev = NULL; 
		struct Node* current = head, * temp = NULL; 
		
		for (size_t i = 1; i < length; ++i)
		{
			temp = (struct Node*)malloc(sizeof(struct Node)); 
			temp->data = *(a + i); 
			temp->prev = current; 
			temp->next = NULL; 
			current->next = temp; 
			current = temp; 
		}
	}
}

size_t size()
{
	size_t i = 0;
	struct Node* p = head; 
	while (p)
	{
		++i; 
		p = p->next; 
	}
	return i; 
}

void display()
{
	struct Node* p = head; 
	while (p)
	{
		printf("%d\n", p->data); 
		p = p->next; 
	}
}

void insertAt(int pos, int elem)
{
	if (pos < 1 || pos > size() + 1)
	{
		fprintf(stderr, "Invalid position\n"); 
		return; 
	}

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->data = elem; 
	

	if (pos == 1)
	{
		temp->next = head; 
		if (head)
			head->prev = temp; 
		head = temp; 
	}
	else
	{
		struct Node* current = head;
		struct Node* p = NULL; 
		for (size_t i = 1; i < pos; ++i)
		{
			p = current; 
			current = current->next;
		}
			
		if (!current)
		{
			temp->next = NULL;
			temp->prev = p; 
			p->next = temp; 
			return; 
		}

		temp->next = current; 
		temp->prev = current->prev; 
		current->prev->next = temp; 
		current->prev = temp; 
	}
}

int deleteAt(int pos)
{
	if (pos<1 || pos > size())
	{
		fprintf(stderr, "Invalid position\n"); 
		exit(EXIT_FAILURE); 
	}
	
	if (head == NULL)
	{
		fprintf(stderr, "List is empty, you cannot remove an element\n"); 
		exit(EXIT_FAILURE); 
	}

	struct Node* removedNode = NULL; 
	int removedData = 0;

	if (pos == 1)
	{
		removedNode = head;
		removedData = head->data; 
		head = head->next; 
		if (head)
			head->prev = NULL; 
		free(removedNode); 
		return removedData; 
	}
	else
	{
		struct Node* current = head;
		for (size_t i = 1; i < pos; ++i)
			current = current->next;
		removedNode = current;
		current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
		removedData = removedNode->data;
		free(removedNode);
		return removedData;
	}
}

void reverse()
{
	if (head == NULL || head->next == NULL) return; 

	struct Node* p = head; 
	struct Node* temp = NULL; 
	while (p)
	{
		temp = p->next; 
		p->next = p->prev;
		p->prev = temp; 
		p = p->prev; 

		if (p && p->next != NULL)
			head = p; 
	}
}