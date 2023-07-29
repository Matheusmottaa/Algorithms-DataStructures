#include <stdio.h> 
#include <stdlib.h>

struct Node { 
    int data; 
    struct Node *next; 
}; 

struct SinglyLinkedList{ 
    unsigned length; 
    struct Node *head; 
}; 

struct SinglyLinkedList *createFromAnArray(const int *, const int);
struct Node *getNode(struct SinglyLinkedList *, int );
void set(struct SinglyLinkedList *, int , int );
void print(const struct SinglyLinkedList *);
void display(struct Node *); // Recursive print
void pushFront(struct SinglyLinkedList *, int );
int removeFront(struct SinglyLinkedList *);
void pushBack(struct SinglyLinkedList *, int);
int removeBack(struct SinglyLinkedList *);
void insertAt(struct SinglyLinkedList *, int , int ); 
int removeAt(struct SinglyLinkedList *, int ); 

int main()
{

    int a[] = {1,2,3,4,5,6,7}; 
    const int arrLen = 7; 
    struct SinglyLinkedList *list = createFromAnArray(a, arrLen); 
    
    insertAt(list,44 ,3); 
    print(list); 
    puts("\n"); 
    printf("Remove an element at index 3: %d\n", removeAt(list, 3)); 
    puts("\n"); 
    print(list); 


    return 0; 
}

struct SinglyLinkedList *createFromAnArray(const int *v, const int length)
{
    struct Node *head, *current, *temp; 
    head = (struct Node *)calloc(1,sizeof(struct Node)); 
    head->data = *v; 
    head->next = NULL; 
    current = head; 

    for(int i=1; i<length; i++)
    {
        temp = (struct Node *)calloc(1,sizeof(struct Node)); 
        temp->data = *(v+i); 
        temp->next = NULL; 

        current->next = temp; 
        current = temp; 
    }
    struct SinglyLinkedList *list = (struct SinglyLinkedList*)calloc(1,sizeof(struct SinglyLinkedList)); 
    list->head = head; 
    list->length = length; 
    return list; 
}

struct Node *getNode(struct SinglyLinkedList *list, int idx)
{
    if(list->head == NULL)
    {
        fprintf(stderr, "Empty List\n"); 
        return NULL; 
    }

    if(idx>=0 && idx<list->length)
    {
        struct Node *current = list->head; 
        size_t i = 0; 
        while(i != idx)
        {
            current = current->next; 
            i++; 
        }
        return current; 
    }
    else
    {
        fprintf(stderr, "Invalid Index\n"); 
        return NULL; 
    }

}

void set(struct SinglyLinkedList *list, int elem, int idx)
{
    if(list->head == NULL)
    {
        fprintf(stderr, "Empty List\n"); 
        return;
    }

    if(idx>=0 && idx<list->length)
    {
        struct Node *node = getNode(list, idx); 
        node->data = elem; 
    }
    else
    { 
        fprintf(stderr, "Invalid Index\n"); 
    }
}

void print(const struct SinglyLinkedList *list)
{
    struct Node *current = list->head; 
    while(current != NULL)
    {
        printf("%d\n", current->data); 
        current = current->next; 
    }
}

void display(struct Node *current)
{
    if(current != NULL)
    {
        printf("%d\n", current->data); 
        display(current->next); 
    }
}

void pushFront(struct SinglyLinkedList *list, int elem)
{
    if(list->head == NULL)
    { 
        struct Node *newNode = (struct Node *)calloc(1,sizeof(struct Node)); 
        newNode->data = elem; 
        newNode->next = NULL; 
        list->head = newNode; 
        list->length++; 
    }
    else
    {
        struct Node *newNode = (struct Node *)calloc(1,sizeof(struct Node)); 
        newNode->data = elem; 
        newNode->next = list->head; 
        list->head = newNode; 
        list->length++; 
    }
}

int removeFront(struct SinglyLinkedList *list)
{
    if(list->head == NULL)
    {
        fprintf(stderr, "Empty List\n"); 
        return ; 
    }
    struct Node *removedNode = list->head;
    const int removedElem = removedNode->data; 
    list->head = removedNode->next; 
    free(removedNode); 
    list->length--; 
    return removedElem; 
}

void pushBack(struct SinglyLinkedList *list, int elem)
{
    if(list->head == NULL)
    {
        struct Node *newNode = (struct Node *)calloc(1,sizeof(struct Node)); 
        newNode->data = elem; 
        newNode->next = NULL; 
        list->head = newNode; 
        list->length++; 
    }
    else
    {
        struct Node *current = list->head; 
        while(current->next != NULL)
        {
            current = current->next; 
        }
        struct Node *newNode = (struct Node *)calloc(1,sizeof(struct Node)); 
        newNode->data = elem; 
        newNode->next = NULL; 
        current->next = newNode; 
        list->length++; 
    }
}

int removeBack(struct SinglyLinkedList *list)
{
    if(list->head == NULL)
    {
        fprintf(stderr, "Empty List\n"); 
        return; 
    }
    struct Node *current = list->head; 
    while(current->next->next != NULL)
    {
        current = current->next; 
    }
    struct Node *removedNode = current->next; 
    current->next = NULL; 
    const int removedElem = removedNode->data; 
    free(removedNode); 
    list->length--; 
    return removedElem; 
}

void insertAt(struct SinglyLinkedList *list, int elem, int idx)
{
    if(idx>=0 && idx<=list->length)
    {
        if(idx == 0 || list->head == NULL)
        {
            pushFront(list, elem); 
        }
        else if(idx == list->length)
        {
            pushBack(list, elem); 
        }
        else
        {
            struct Node *prevNode = getNode(list, idx-1); 
            struct Node *newNode = (struct Node *)calloc(1,sizeof(struct Node)); 
            newNode->data = elem; 
            newNode->next= prevNode->next; 
            prevNode->next = newNode; 
            list->length++; 
        }
        return; 
    }

    fprintf(stderr, "Invalid Index\n"); 
}

int removeAt(struct SinglyLinkedList *list, int idx)
{
    if(list->head == NULL)
    {
        fprintf(stderr, "Empty List\n"); 
        return; 
    }

    if(idx>=0 && idx<list->length)
    {
        int removedElem = 0; 

        if(idx == 0)
        {
            removedElem = removeFront(list); 
        }
        else if(idx == list->length-1)
        {
            removedElem = removeBack(list); 
        }
        else 
        {
            struct Node *prevNode = getNode(list, idx-1); 
            struct Node *removedNode = prevNode->next; 
            prevNode->next = removedNode->next; 
            removedElem = removedNode->data; 
            free(removedNode);
            list->length--; 
        }
        return removedElem; 
    }
    fprintf(stderr, "Invalid Index\n"); 
    return; 
}