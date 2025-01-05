#include <iostream>
#include <vector>
#include <climits>

using namespace std; 

struct Node
{
	int data;
	struct Node* next;
}*head = nullptr; 

void createListFromVector(const vector<int>&);
void display(); 
size_t count();
void insertFirst(int); 
void insertLast(int);
void insertAt(int, int);
int removeFirst(); 
int removeLast(); 
int removeAt(int); 
bool isSorted();
void insertSort(int); 
int findMin(struct Node*);
int findMax(struct Node*);
void removeDuplicates(); 
void removeDuplicatesFromSortedList(); 
void displayReverse(struct Node *); 
void reverse(); 
void recursiveReverse(struct Node*, struct Node*); 

int main()
{
	vector<int> vec; 
	vec.push_back(2); 
	vec.push_back(3); 
	vec.push_back(3); 
	vec.push_back(4); 
	vec.push_back(4); 
	vec.push_back(4); 
	vec.push_back(5); 
	vec.push_back(6); 
	vec.push_back(6); 
	vec.push_back(7); 

	createListFromVector(vec);
	
	display(); 

	cout << endl; 
	removeDuplicatesFromSortedList(); 
	display(); 

	cout << endl; 

	//displayReverse(head); 
	//reverse(); 
	recursiveReverse(head, nullptr); 
	display(); 

	return 0; 
}


void createListFromVector(const vector<int> &v)
{
	if (v.size() > 0)
	{
		head = (struct Node*)malloc(sizeof(struct Node)); 
		head->data = v[0]; 
		head->next = nullptr; 
		struct Node* current = head, * temp = nullptr; 

		for (size_t i = 1; i < v.size(); i++)
		{
			temp = (struct Node*)malloc(sizeof(struct Node)); 
			temp->data = v[i]; 
			temp->next = nullptr; 
			current->next = temp; 
			current = temp; 
		}
	}
}

void display()
{
	struct Node* current = head; 
	while (current)
	{
		cout << current->data << endl; 
		current = current->next; 
	}
}

void insertFirst(int elem)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 
	newNode->next = head; 
	head = newNode; 
}

void insertLast(int elem)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 
	newNode->next = nullptr; 

	if (head == nullptr)
		head = newNode; 
	else
	{
		struct Node* current = head; 
		while (current->next)
			current = current->next; 
		current->next = newNode; 
	}

}

size_t count()
{
	struct Node* current = head; 
	size_t i = 0; 
	while (current)
	{
		i++; 
		current = current->next; 
	}
	return i;
}

void insertAt(int pos, int elem)
{
	if (pos<1 || pos > count()+1)
	{
		cerr << "Invalid Position\n"; 
		return; 
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 
	
	if (pos == 1 || head == nullptr)
	{
		newNode->next = head; 
		head = newNode; 
	}
	else
	{
		struct Node* current = head;
		for (size_t i = 0; i < pos - 2; i++)
			current = current->next;
		newNode->next = current->next;
		current->next = newNode;
	}
}

int removeFirst()
{
	if (head == nullptr)
	{
		cerr << "Impossible to remove from an empty list!"; 
		exit(EXIT_FAILURE); 
	}
	struct Node* removed = head; 
	head = removed->next; 
	int rdata = removed->data; 
	delete removed; 
	return rdata; 
}

int removeLast()
{
	if (head == nullptr)
	{
		cerr << "Impossible to remove from an empty list!";
		exit(EXIT_FAILURE);
	}

		int rdata = 0; 

	if (head->next == nullptr)
	{
		rdata = head->data;  
		delete head; 
		head = nullptr; 
		return rdata; 
	}
	
	struct Node* current = head; 
	while (current->next&&current->next->next)
		current = current->next; 

	struct Node* removed = current->next; 
	current->next = nullptr; 
	rdata = removed->data; 
	delete removed; 
	return rdata; 
}

int removeAt(int pos)
{
	if (pos<1 || pos>count())
	{
		cerr << "Invalid Position\n"; 
		exit(EXIT_FAILURE); 
	}

	struct Node* removed = nullptr; 
	int rdata = INT_MIN; 

	if (pos == 1)
	{
		removed = head; 
		head->next == removed->next; 
		rdata = removed->data;
		free(removed);
		return rdata; 
	}

	struct Node* current = head; 
	for (size_t i = 0; i < pos - 2; i++)
		current = current->next; 
	removed = current->next; 
	current->next = removed->next; 
	rdata = removed->data; 
	free(removed); 
	return rdata; 
}

bool isSorted()
{
	struct Node* current = head; 
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return false; 
		current = current->next; 
	}
	return true; 
}

void insertSort(int elem)
{
	if (!isSorted())
	{
		cerr << "List is not sorted\n"; 
		return; 
	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 
	if (head == nullptr || elem < head->data)
	{
		newNode->next = head; 
		head = newNode; 
	}
	else
	{
		struct Node* current = head; 
		while (current->next && current->next->data < elem)
			current = current->next; 
		newNode->next = current->next; 
		current->next = newNode;  
	}
}


int findMin(struct Node* p)
{
	if (p)
	{
		int x = findMin(p->next); 
		return x < p->data ? x : p->data; 
	}
	return INT_MAX; 
}

int findMax(struct Node* p)
{
	if (p)
	{
		int x = findMax(p->next); 
		return x > p->data ? x : p->data; 
	}
	return INT_MIN; 
}

void removeDuplicates()
{
	struct Node* current = head; 
	while (current)
	{
		struct Node* aux = current; 
		while (aux && aux->next)
		{
			if (aux->next->data == current->data)
			{
				struct Node* removed = aux->next;
				aux->next = removed->next;
				free(removed);
			}
			else
				aux = aux->next; 
		}
		current = current->next; 
	}
}

void removeDuplicatesFromSortedList()
{
	if (!isSorted())
	{
		cerr << "List is not sorted\n"; 
		return; 
	}

	struct Node* current = head; 
	struct Node* next = nullptr; 
	while (current && current->next)
	{
		next = current->next; 
		if (current->data == next->data)
		{
			current->next = next->next; 
			free(next); 
			next = current->next; 
		}
		else
		{
			current = next;
			next = next->next; 
		}
	}
}

void displayReverse(struct Node *p)
{
	if (p)
	{
		displayReverse(p->next); 
		cout << p->data << endl; 
	}
}

void reverse()
{
	struct Node* current = head, * prev = nullptr, * next = nullptr; 
	while (current)
	{
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	}
	head = prev; 
}

void recursiveReverse(struct Node* p, struct Node* q)
{
	if (p)
	{
		recursiveReverse(p->next, p);
		p->next = q;
	}
	else
		head = q; 
}
