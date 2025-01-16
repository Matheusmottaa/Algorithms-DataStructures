#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int size; 
	int top; 
	char* data; 
};

struct Stack *createStack(int); 
void push(struct Stack*, char); 
char pop(struct Stack*); 
char peek(const struct Stack*, int); 
int isEmpty(const struct Stack*);
int isFull(const struct Stack*); 
char stackTop(const struct Stack*); 
int isBalance(const char *str); 

int main()
{
	struct Stack* st = createStack(5); 


	push(st, 'A'); 
	push(st, 'B'); 
	push(st, 'C'); 
	push(st, 'D'); 
	push(st, 'E');

	for (size_t i = 1; i <= 5; ++i)
		printf("peek(%d) = %c\n", i, peek(st, i)); 
	
	puts("\n"); 

	const char* exp = "(a+b) + (c*d))"; 
	printf("Is expression balanced? %s\n", (isBalance(exp) ? "Yes" : "No"));
	
	return 0;
}


struct Stack* createStack(int size)
{
	struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack)); 
	temp->size = size;
	temp->data = (char*)malloc(sizeof(char) * size); 
	temp->top = -1; 
	return temp; 
}

void push(struct Stack *st, char elem)
{
	if (st->top == st->size-1)
	{
		printf("Stack overflow!\n"); 
		return; 
	}
	st->data[++st->top] = elem; 
}

char pop(struct Stack* st)
{
	if (st->top == -1)
	{
		printf("Stack Underflow!\n"); 
		exit(EXIT_FAILURE); 
	}
	char elem = st->data[st->top--]; 
	return elem; 
}

char peek(const struct Stack* st, int pos)
{
	if (st->top-pos+1<0)
	{
		printf("Invalid Position\n"); 
		exit(EXIT_FAILURE); 
	}

	return st->data[st->top - pos + 1]; 
}


int isEmpty(const struct Stack* st)
{
	return st->top == -1; 
}

int isFull(const struct Stack* st)
{
	return st->top == st->size-1; 
}

char stackTop(const struct Stack* st)
{
	if (st->top == -1)
	{
		printf("Empty Stack!\n"); 
		exit(EXIT_FAILURE); 
	}
	return st->data[st->top]; 
}

int isBalance(const char* exp)
{
	struct Stack st; 
	st.size = strlen(exp); 
	st.top = -1; 
	st.data = (char*)calloc(st.size, sizeof(char));
	for (size_t i = 0; exp[i] != '\0'; ++i)
	{
		if (exp[i] == '(')
			push(&st, exp[i]); 
		else if (exp[i] == ')')
		{
			if (st.top == -1)
				return 0; 
			pop(&st); 
		}
	}
	return st.top == -1 ? 1 : 0; 
}