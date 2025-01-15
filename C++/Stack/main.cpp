#include <iostream>
#include <string>

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
	int size; 
	T* data; 
	int top; 
public: 

	Stack(int); 
	~Stack(); 
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	void push(T); 
	T pop(); 
	T peek(int); 
	T stackTop(); 
	bool isEmpty(); 
	bool isFull(); 
};

int main()
{

	Stack<string> names = Stack<string>(5);
	try 
	{
		names.push("Jordan");
		names.push("Lebron");
		names.push("Setph");
		names.push("Kyrie");
		for (size_t i = 0; i < 4; ++i)
			cout << names.peek(i) << endl;
	}
	catch (Error e)
	{
		cout << e.getMessage() << endl; 
	}
	return 0; 
}

template<typename T>
Stack<T>::Stack(int size)
{
	this->size = size; 
	this->data = new T[this->size]; 
	this->top = -1; 
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] this->data; 
}

template<typename T>
Stack<T>::Stack(const Stack& other) {
	size = other.size;
	data = new T[size];
	top = other.top;
	for (int i = 0; i <= top; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this != &other) {
		delete[] data; 
		size = other.size;
		data = new T[size];
		top = other.top;
		for (int i = 0; i <= top; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template<typename T> 
void Stack<T>::push(T elem)
{
	if (size-1 == top)
		throw Error("Stack Overflow!"); 

	data[++top] = elem; 
}

template<typename T> 
T Stack<T>::pop()
{
	if (top==-1)
		throw Error("Stack Underflow!"); 

	T elem = data[top--]; 
	return elem; 
}

template<typename T> 
bool Stack<T>::isEmpty()
{
	return top == -1; 
}

template<typename T>
bool Stack<T>::isFull()
{
	return size - 1 == top; 
}

template<typename T> 
T Stack<T>::peek(int idx)
{
	if (idx<0 || idx>top)
		throw Error("Invalid Index! " + to_string(idx)); 
	return data[top-idx]; 
}

template<typename T> 
T Stack<T>::stackTop()
{
	if (top == -1)
		throw Error("Empty Stack!"); 
	return data[top]; 
}
