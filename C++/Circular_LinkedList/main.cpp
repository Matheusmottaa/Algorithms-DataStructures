#include <iostream>
#include <vector>

using namespace std; 

struct Node
{
	int data;
	struct Node* next;

	Node(int data) : data(data), next(nullptr) {}

}*head = nullptr; 

void createListFromVector(const vector<int>&);
void display();
void print(Node*);
void insertAt(int, int);
int removeAt(int); 
size_t size();  
void reverse(); 

int main()
{
	vector<int> vec; 
	vec.push_back(2); 
	vec.push_back(4); 
	vec.push_back(7); 

	createListFromVector(vec);
	insertAt(4, 12); 
	print(head); 

	cout << endl; 

	reverse(); 
	display(); 
	
	cout << "List length: " << size() << endl; 
	
	cout << endl; 

	cout << "Removing an elment at position 3: " << removeAt(3) << endl; 
	display(); 
	cout << "List length: " << size() << endl; 

	return 0; 
}

void createListFromVector(const vector<int>& v)
{
	if (v.size() > 0)
	{
		head = new Node(v[0]); 
		head->next = head; 
		Node* current = head, * newNode = nullptr; 
		for (size_t i = 1; i < v.size(); ++i)
		{
			newNode = new Node(v[i]);
			current->next = newNode; 
			current = newNode; 
		}
		current->next = head; 
	}
}

void display()
{
	Node* p = head;  
	do
	{
		cout << p->data << endl; 
		p = p->next; 
	} while (p != head); 
}

void print(Node* p)
{
	cout << p->data << endl;
	if (p->next != head)
		print(p->next);
}

size_t size()
{
	struct Node* p = head; 
	size_t i = 0; 
	do
	{
		p = p->next; 
		++i; 
	} while (p != head);
	return i; 
}

void insertAt(int pos, int elem)
{
	Node* newNode = new Node(elem), * current = head; 

	if (pos<1 || pos>size() + 1)
	{
		cerr << "Invalid Position\n"; 
		return; 
	}

	if (head == nullptr)
	{
		newNode->next = newNode; 
		head = newNode; 
	}
	else if (pos == 1 && head != nullptr)
	{
		while (current->next != head)
			current = current->next; 
		current->next = newNode; 
		newNode->next = head; 
		head = newNode; 
	}
	else
	{
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		newNode->next = current->next; 
		current->next = newNode; 
	}	
}

void reverse()
{
	if (!head || head->next == head) return; 

	Node* current = head, * prev = nullptr, * next = nullptr; 
	do
	{
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} while (current != head);
	head->next = prev; 
	head = prev; 
}

int removeAt(int pos)
{
	if (pos<1 || pos>size())
	{
		cerr << "Invalid Position\n"; 
		exit(EXIT_FAILURE);
	}

	if (head == nullptr)
	{
		cerr << "Empty List\n"; 
		exit(EXIT_FAILURE); 
	}
	struct Node* removedNode = nullptr;
	struct Node* current = head; 
	int rdata = 0; 
	if (pos == 1)
	{
		removedNode = head;
		rdata = removedNode->data; 
		while (current->next != head)
			current = current->next; 

		head = removedNode->next; 
		current->next = head;
		delete removedNode; 
		return rdata; 
	}
	else
	{
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		removedNode = current->next; 
		current->next = removedNode->next; 
		rdata = removedNode->data; 
		delete removedNode; 
		return rdata; 
	}
}