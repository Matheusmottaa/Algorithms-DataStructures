#include <iostream>
#include <vector>

using namespace std; 

struct Node
{
	int data; 
	struct Node* prev; 
	struct Node* next; 
}*first;

void createListFromVector(const vector<int>&);
void display();
void insertAt(int, int); 
size_t size(); 
int deleteAt(int); 
void reverse(); 

int main()
{
	vector<int> vec; 
	vec.push_back(4); 
	vec.push_back(7);
	vec.push_back(10); 
	vec.push_back(12); 

	createListFromVector(vec); 
	insertAt(size(), 11);

	int pos = size() - 2; 


	display(); 

	cout << endl; 

	cout << "Delete element at position" << pos << ":" << deleteAt(pos) << endl;

	display(); 


	cout << endl; 

	reverse(); 

	display(); 


	return 0;
}

void createListFromVector(const vector<int>& v)
{
	if (v.size() > 0)
	{
		struct Node* current, * temp; 
		current = temp = nullptr; 

		first = (struct Node*)malloc(sizeof(struct Node)); 
		first->prev = nullptr; 
		first->next = nullptr;
		first->data = v[0]; 
		current = first; 

		for (size_t i = 1; i < v.size(); ++i)
		{
			temp = (struct Node*)malloc(sizeof(struct Node)); 
			temp->data = v[i]; 
			temp->next = nullptr; 
			temp->prev = current; 
			current->next = temp; 
			current = temp; 
		}
	}
}

void display()
{
	struct Node* current = first; 
	while (current)
	{
		cout << "[" << (int*)current->prev << " | " << current->data << " | " << (int*)current->next << "]\n"; 
		current = current->next; 
	}
}

size_t size()
{
	struct Node* p = first; 
	size_t i = 0; 
	while (p)
	{
		++i; p = p->next; 
	}
	return i; 
}


void insertAt(int pos, int elem)
{
	if (pos<1 || pos > size() + 1)
	{
		cerr << "Invalid Position\n"; 
		return; 
	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = elem; 
	if (pos == 1)
	{
		newNode->next = first; 
		if (first == nullptr)
			newNode->prev = nullptr;
		else
			first->prev = newNode; 

		first = newNode; 
	}
	else
	{
		struct Node* p = first, *q = nullptr; 
		for (size_t i = 1; i < pos; ++i)
		{
			q = p; 
			p = p->next; 
		}
		if (!p)
		{
			q->next = newNode; 
			newNode->prev = q; 
			newNode->next = nullptr; 
		}
		else
		{
			newNode->next = p; 
			p->prev = newNode; 
			newNode->prev = q; 
			q->next = newNode; 
		}
	}
}

int deleteAt(int pos)
{
	if (pos < 1 || pos >= size())
	{
		cerr << "Invalid Position\n";
		exit(EXIT_FAILURE); 
	}

	if (first == nullptr)
	{
		cerr << "Empty List!\n"; 
		exit(EXIT_FAILURE); 
	}

	struct Node* temp = nullptr; 
	int rdata = 0; 
	if (pos == 1)
	{
		temp = first;
		first = first->next; 
		if(first)
			first->prev = nullptr; 
		rdata = temp->data; 
		delete temp; 
		return rdata; 
	}
	else
	{
		struct Node* p = first; 
		for (size_t i = 1; i < pos; ++i)
			p = p->next; 

		temp = p;
		if (p->next)
			p->next->prev = p->prev; 
		p->prev->next = p->next; 
		rdata = temp->data; 
		delete temp; 
		return rdata; 
	}
}

void reverse()
{
	if (first == nullptr || first->next == nullptr) return; 


	struct Node* p = first; 
	struct Node* temp = nullptr; 
	while (p)
	{
		temp = p->next; 
		p->next = p->prev; 
		p->prev = temp; 
		p = p->prev; 
		if (p!= nullptr && p->next == nullptr)
			first = p; 
	}
}