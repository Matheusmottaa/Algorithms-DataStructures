#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char data; 
	struct Node* next; 
}*top=NULL;

void push(char); 
char pop(); 
char peek(int); 
char stackTop(); 
int isEmpty(); 
int isFull(); 
size_t size(); 
int isBalence(const char *); 
int isBalence(const char*);
int isOperand(char); 
int precedence(char);


int main()
{
	const char* exp = "((a+b)*(c-d))"; 

	printf("Is the expression balanced? %s\n", (isBalence(exp) ? "Yes" : "No"));

	/*	
		push('A');
		push('B');
		push('C');
		push('D');

		for (size_t i = 1; i <= 4; ++i)
			printf("%c\n", peek(i));

		printf("Removendo: %c\n", pop());
		printf("Removendo: %c\n", pop());

		puts("\n");

		for (size_t i = 1; i <= 2; ++i)
			printf("%c\n", peek(i));
	*/
	
	return 0; 
}

void push(char elem)
{
	struct Node* newNode = (struct Node *) malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Stack Overflow!\n"); 
		return; 
	}
	newNode->data = elem; 
	newNode->next = top; 
	top = newNode; 
}

char pop()
{
	if (top == NULL)
	{
		fprintf(stderr, "Stack Underflow!\n"); 
		exit(EXIT_FAILURE); 
	}

	char x = -1; 

	struct Node* removed = top; 
	top = top->next; 
	x = removed->data; 
	free(removed); 
	return x; 
}


char peek(int pos)
{
	if (pos<1 || pos>size())
	{
		fprintf(stderr, "Invalid position\n"); 
		exit(EXIT_FAILURE); 
	}

	struct Node* p = top; 
	for (size_t i = 1; i != pos; ++i)
		p = p->next; 
	return p->data; 
}

int isFull()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	int aux = temp ? 1 : 0; 
	free(temp); 
	return aux; 
}

int isEmpty()
{
	return top == NULL; 
}

char stackTop()
{
	if (top == NULL)
	{
		fprintf(stderr, "Empty stack!"); 
		exit(EXIT_FAILURE); 
	}
	return top->data; 
}

size_t size()
{
	size_t i = 0; 
	struct Node* p = top; 
	while (p)
	{
		++i; 
		p = p->next; 
	}
	return i; 
}

int isBalence(const char* exp)
{
	for (size_t i = 0; exp[i] != '\0'; ++i)
	{
		if (exp[i] == '(')
			push(exp[i]); 
		else if (exp[i] == ')')
		{
			if (isEmpty())
				return 0; 
			pop(); 
		}
	}
	return isEmpty() ? 1 : 0; 
}

int isOperand(char x)
{
	return x != '*' && x != '/'  && x != '+' && x != '-';
}

int precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2; 
	return 0; 
}

char* convert(const char* infix)
{
	char* postfix = (char*)malloc(sizeof(char) * strlen(infix) + 1); 
	int i = 0, j = 0; 

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++]; 
		else
		{
			if (isEmpty() || precedence(infix[i]) > precedence(top->data))
				push(infix[i++]);
			else
				postfix[j++] = pop(); 
		}
	}

	while (top != NULL)
	{
		postfix[j++] = pop(); 
	}
	postfix[j] = '\0'; 
	return postfix; 
}
