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
struct Node
{
	T data; 
	Node* next; 

	Node(T data): data(data), next(nullptr) {}
};

template<typename T>
class CircularList
{
private: 
	Node<T>* head; 
public: 
	CircularList(); 
	~CircularList(); 
	void createListFromVector(const vector<T>&); 
	size_t size(); 
	void insertAt(T, int); 
	T removeAt(int); 
	void display(); 
	void reverse(); 
};


int main()
{
	vector<string> vec; 
	vec.push_back("Gon"); 
	vec.push_back("Netero"); 
	vec.push_back("Killua");

	try
	{
		CircularList<string> list;
		list.createListFromVector(vec); 
		list.insertAt("Leorio", 1);
		list.display();
		cout << "Size of the list: " << list.size() << endl;

		cout << endl;

		list.reverse(); 
		list.display(); 
		cout << "Size of the list: " << list.size() << endl;
	}
	catch (IllegalOperation e)
	{
		cout << e.getMessage() << endl;
	}
	
	return 0; 
}

template<typename T> 
CircularList<T>::CircularList()
{
	this->head = nullptr; 
}

template<typename T> 
CircularList<T>::~CircularList()
{
	if (head == nullptr)
		return; 

	struct Node<T>* current = head; 
	struct Node<T>* aux = nullptr; 
	do
	{
		aux = current->next; 
		delete current; 
		current = aux; 
	} while (current != head);
	head = nullptr; 
}


template<typename T> 
void CircularList<T>::createListFromVector(const vector<T>& v)
{
	if (v.size() > 0)
	{
		this->head = new Node<T>(v[0]); 
		this->head->next = head; 
		Node<T>* current = head, * temp = nullptr; 
		for (size_t i = 1; i < v.size(); ++i)
		{
			temp = new Node<T>(v[i]); 
			current->next = temp; 
			current = temp; 
		}
		current->next = this->head; 
	}
	else
		throw IllegalOperation("It's not possible to create a list from an empty vector!"); 
}

template<typename T> 
void CircularList<T>::display()
{
	if (this->head == nullptr) return; 

	Node<T>* current = this->head; 
	do
	{
		cout << current->data << endl; 
		current = current->next; 
	} while (current != head); 
}

template<typename T> 
size_t CircularList<T>::size()
{
	if (this->head == nullptr)
		return 0; 
	struct Node<T>* current = this->head; 
	size_t i = 0; 
	do
	{
		i++; 
		current = current->next; 
	} while (current != head);
	return i; 
}

template<typename T>
void CircularList<T>::insertAt(T elem, int pos)
{
	if (pos<1 || pos>size() + 1) throw IllegalOperation("Invalid position!"); 

	Node<T>* newNode = new Node<T>(elem); 
	if (head == nullptr)
	{
		newNode->next = newNode; 
		head = newNode; 
	}
	else if (pos == 1)
	{
		Node<T>* current = head; 
		while (current->next != head)
			current = current->next; 
		current->next = newNode; 
		newNode->next = head; 
		head = newNode; 
	}
	else
	{
		struct Node<T>* current = head; 
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		newNode->next = current->next; 
		current->next = newNode; 
	}
}

template<typename T> 
T CircularList<T>::removeAt(int pos)
{
	if (pos<1 || pos>size()) throw IllegalOperation("Invalid Position!"); 

	if (head == nullptr)
		throw IllegalOperation("Invalid Operation, list is empty!"); 

	Node<T>* removed = nullptr; 
	Node<T>* current = nullptr; 
	T removedData; 
	
	if (pos == 1)
	{
		if (head->next == head)
		{
			removedData = this->head->data; 
			delete head; 
			head = nullptr; 
			return removedData; 
		}
		else
		{
			current = head;
			removed= head;
			while (current->next != head)
				current = current->next; 
			
			current->next = head->next; 
			head = head->next; 
			removedData = removed->data;
			delete removed;  
			return removedData; 
		}
	}
	else
	{
		current = head; 
		for (size_t i = 0; i < pos - 2; ++i)
			current = current->next; 
		removed = current->next; 
		current->next = removed->next; 
		removedData = removed->data; 
		delete removed; 
		return removedData; 
	}

}

template<typename T> 
void CircularList<T>::reverse()
{
	if (!head || !head->next) return; 
	Node<T>* current = this->head, * prev = nullptr, * next = nullptr; 
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