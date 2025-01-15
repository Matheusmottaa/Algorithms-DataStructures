#include <iostream>

using namespace std; 


class Error
{
private: 
	string message; 
public: 
	Error(const string& message)
	{
		this->message = message; 
	}

	string getMessage()
	{
		return message; 
	}
};

template<typename T>
class Stack
{
private: 

	template<typename T> 
	struct Node
	{
		T data; 
		struct Node* next; 

		Node(T data): data(data), next(nullptr) {}
	};

	Node<T>* top;
	int size; 
public: 
	Stack(); 
	~Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	void push(T); 
	T pop(); 
	bool isEmpty(); 
	T stackTop(); 
	T peek(int); 
};

int main()
{
	Stack<string> names = Stack<string>();
	try
	{
		names.push("Goku");
		names.push("Vegeta");
		names.push("Naruto");
		names.push("Rock Lee");
	
		for(size_t i=0; i<4; ++i)
			cout << names.peek(i) << endl; 

		cout << endl; 

		for (size_t i = 0; i < 4; ++i)
			cout << "Remove: " <<  names.pop() << endl;
		
		cout << endl; 
		cout << "Is stack empty? " << (names.isEmpty() ? "Yes\n" : "No\n");
	}
	catch (Error e)
	{
		cerr << e.getMessage() << endl; 
	}
	return 0; 
}

template<typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template<typename T>
Stack<T>::~Stack()
{
	Node<T>* current = top, * prev = nullptr; 
	while (current)
	{
		prev = current; 
		current = current->next;
		delete prev; 
	}
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	if (!other.top) return;

	Node<T>* temp = other.top;
	Stack<T> reverseStack;
	
	while (temp)
	{
		reverseStack.push(temp->data);
		temp = temp->next;
	}

	while (!reverseStack.isEmpty())
		this->push(reverseStack.pop());
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other) return *this; 
	this->~Stack();
	top = nullptr;
	size = 0;
	Node<T>* temp = other.top;
	Stack<T> reverseStack;

	while (temp)
	{
		reverseStack.push(temp->data);
		temp = temp->next;
	}

	while (!reverseStack.isEmpty())
		this->push(reverseStack.pop());

	return *this;
}

template<typename T> 
void Stack<T>::push(T elem)
{
	Node<T>* temp = new Node<T>(elem); 
	if (temp == nullptr)
		throw Error("Stack Overflow!"); 
	
	temp->next = top; 
	top = temp; 
	this->size++; 
}


template<typename T> 
T Stack<T>::pop()
{
	if (top == nullptr)
		throw Error("Stack Underflow!"); 

	Node<T>* temp = top; 
	T data = temp->data; 
	top = temp->next; 
	delete temp; 
	this->size--; 
	return data; 
}

template<typename T> 
bool Stack<T>::isEmpty()
{
	return this->top == nullptr; 
}

template<typename T> 
T Stack<T>::stackTop()
{
	if (top == nullptr)
		throw Error("Empty stack!"); 
	return this->top->data; 
}

template<typename T> 
T Stack<T>::peek(int idx)
{
	if (idx < 0 || idx >= this->size)
		throw Error("Invalid Index!"); 

	Node<T> *current = top;   
	for (size_t i = 0; i!=idx; ++i)
		current = current->next;
	return current->data; 
}