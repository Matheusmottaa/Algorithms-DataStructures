#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Node
{
	int data; 
	struct Node* next; 
}*head = NULL;

void createListFromArray(const int*, int); 
size_t size(); 
void display(); 
void insertAt(int, int); 
int deleteAt(int); 
void reverse(); 

int main()
{
	int a[SIZE] = { 4,5,9, 11,23 }; 

	createListFromArray(a, SIZE); 	
	insertAt(size()+1, 47);
	display(); 
	printf("Size of the list: %d\n", size()); 

	puts("\n"); 
	
	int position = 3; 
	printf("Delete an element at position %d: %d\n", position, deleteAt(position)); 
	display(); 
	printf("Size of the list: %d\n", size()); 

	puts("\n"); 

	reverse(); 
	display(); 
	return 0; 
}

void createListFromArray(const int* a, int size)
{
	if (size > 0)
	{
		head = (struct Node*)malloc(sizeof(struct Node)); 
		head->data = a[0]; 
		head->next = NULL; 
		struct Node* current = head, * temp = NULL; 

		for (size_t i = 1;i < size; ++i)
		{
			temp = (struct Node*)malloc(sizeof(struct Node)); 
			temp->data = a[i]; 
			temp->next = NULL; 
			current->next = temp; 
			current = temp; 
		}
		current->next = head; 
	}
}

size_t size()
{
	if (head == NULL)
		return 0; 

	size_t i = 0;
	struct Node* current = head; 
	do
	{
		++i; 
		current = current->next; 
	} while (current != head); 
	return i; 
}

void display()
{
	if (!head)
		return; 
	struct Node* current = head; 
	do
	{
		printf("%d\n", current->data); 
		current = current->next; 
	} while (current != head); 
}

void insertAt(int pos, int elem)
{
	if (pos<0 || pos>size() + 1)
	{
		fprintf(stderr, "Invlaid Position\n"); 
		return; 
	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 

	if (pos == 1)
	{
		if (head == NULL)
			newNode->next = newNode; 
		else
		{
			struct Node* current = head; 
			while (current->next != head)
				current = current->next; 
			newNode->next = head; 
			current->next = newNode; 
		}
		head = newNode; 
	}
	else
	{
		struct Node* current = head; 
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		newNode->next = current->next; 
		current->next = newNode; 
	}

}

int deleteAt(int pos)
{
	if (pos<1 || pos>size())
	{
		fprintf(stderr, "Invalid position\n"); 
		exit(EXIT_FAILURE); 
	}

	if (head == NULL)
	{
		fprintf(stderr, "Impossible to remove an element from an empty list\n"); 
		exit(EXIT_FAILURE); 
	}

	struct Node* removedNode = NULL; 
	int removedData = 0; 
	if (pos == 1)
	{
		removedNode = head; 
		if(head->next!=NULL)
		{
			struct Node* current = head; 
			while (current->next != head)
				current = current->next;
			current->next = head->next; 
		}
		head = head->next; 
		removedData = removedNode->data;
		free(removedNode); 
		return removedData; 
	}
	else
	{
		struct Node* current = head; 
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		removedNode = current->next; 
		current->next = removedNode->next; 
		removedData = removedNode->data; 
		free(removedNode); 
		return removedData; 
	}
}

void reverse()
{
	if (head == NULL || head->next == NULL) return; 

	struct Node* current = head; 
	struct Node* prev, * next; 
	prev = next = NULL; 

	do
	{
		next = current->next; 
		current->next = prev;
		prev = current; 
		current = next; 
	} while (current != head);
	current->next = prev; 
	head = prev; 
}