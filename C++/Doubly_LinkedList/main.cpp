#include <iostream>
#include <vector>

using namespace std; 

class IllegalOperation
{
private: 
	string message; 
public: 
	IllegalOperation(string message)
	{
		this->message = message; 
	}

	string getMessage()
	{
		return message; 
	}
};


template<typename T>
class DoublyLinkedList
{
private: 

	template<typename T>
	struct Node
	{
		Node* next;
		Node* prev;
		T data;

		Node(T data) : data(data), next(nullptr), prev(nullptr){}
	};

	Node<T>* first; 

public: 
	DoublyLinkedList(); 
	~DoublyLinkedList(); 
	void createListFromVector(const vector<T>&);
	size_t size(); 
	void display(); 
	void insertAt(int, T); 
	T deleteAt(int);
	void reverse(); 
};


int main()
{
	vector<string> vec; 

	vec.push_back("Ronaldo Nazario"); 
	vec.push_back("Pele"); 
	vec.push_back("Messi");
	vec.push_back("Neymar");
	vec.push_back("Ronaldinho"); 
	vec.push_back("Cristiano Ronaldo");

	DoublyLinkedList<string> list; 

	list.createListFromVector(vec); 

	list.display(); 
	cout << "Length of the list: " << list.size() << endl; 
}

template<typename T> 
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->first = nullptr; 
}

template<typename T> 
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (first)
	{
		Node<T>* current = first; 
		Node<T>* temp = nullptr; 
		while (current)
		{
			temp = current;
			current = current->next;
			delete temp; 
		}
	}
}

template<typename T> 
void DoublyLinkedList<T>::createListFromVector(const vector<T> &v)
{
	if (v.size() > 0)
	{
		Node<T>* current = nullptr, * temp = nullptr; 
		first = new Node<T>(v[0]); 
		current = first; 

		for (size_t i = 1; i < v.size(); ++i)
		{
			temp = new Node<T>(v[i]); 
			current->next = temp; 
			temp->prev = current; 
			current = temp; 
		}
	}
}

template<typename T>
void DoublyLinkedList<T>::display()
{
	struct Node<T>* p = first; 
	while (p)
	{
		cout << p->data << endl; 
		p = p->next; 
	}
}

template<typename T> 
size_t DoublyLinkedList<T>::size()
{
	size_t i = 0; 
	Node<T>* p = first; 
	while (p)
	{
		++i; 
		p = p->next; 
	}
	return i; 
}

template<typename T> 
void DoublyLinkedList<T>::insertAt(int pos, T elem)
{
	if (pos < 1 || pos>size() + 1) throw IllegalOperation("Invalid position\n"); 


	Node<T>* newNode = new Node<T>(elem); 
	if (pos == 1)
	{
		newNode->next = first; 
		if (first != nullptr)
			first->prev = newNode; 
		first = newNode; 
	}
	else
	{
		Node<T>* current = first; 
		Node<T>* p = nullptr; 
		for (size_t i = 1; i < pos; ++i)
		{
			p = current; 
			current = current->next;
		}
			
		if (!current)
		{
			newNode->prev = p; 
			p->next = newNode; 
			return;
		}
		newNode->prev = current->prev; 
		newNode->next = current; 
		current->prev->next = newNode; 
		current->prev = newNode; 
	}
}

template<typename T> 
T DoublyLinkedList<T>::deleteAt(int pos)
{
	if (pos<1 || pos > size()) throw IllegalOperation("Invalid Position\n"); 

	if (this->first == nullptr) throw IllegalOperation("Impossible to remove an element from an empty list!\n");

	Node<T> *removed = nullptr; 
	T removedData; 
	if (pos == 1)
	{
		removed = first; 
		first = first->next;
		if (first)
			first->prev = nullptr; 
		removedData = removed->data; 
		delete removed; 
		return removedData; 
	}
	else
	{
		Node<T>* current = first; 
		for (size_t i = 1; i < pos; ++i)
			current = current->next; 

		removed = current; 
		current->prev->next = current->next; 
		if (current->next)
			current->next->prev = current->prev; 
		removedData = current->data; 
		delete removed; 
		return removedData; 
	}
}

template<typename T> 
void DoublyLinkedList<T>::reverse()
{
	if (first == nullptr || first->next == nullptr) return; 

	Node<T>* p = first; 
	Node<T>* temp = nullptr; 
	while (p)
	{
		temp = p->next; 
		p->next = p->prev; 
		p->prev = temp; 
		p = p->prev; 
		if (p && !p->next)
			first = p; 
	}
}