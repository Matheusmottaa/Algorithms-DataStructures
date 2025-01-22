#include <iostream>
#include <stdexcept>

using namespace std; 

class Error : public runtime_error {
public:
	explicit Error(const string& message) : runtime_error(message) {}
};

template<typename T> 
class Queue
{
private: 
	int size; 
	int front; 
	int back;
	T* data; 
public: 
	explicit Queue(int);
	~Queue(); 
	Queue(const Queue&); 
	Queue& operator=(const Queue&);
	void enqueue(T); 
	T dequeue(); 
	T first() const; 
	T last() const; 
	bool isEmpty() const; 
	bool isFull() const;
};

int main()
{
	Queue<float> numbers = Queue<float>(6);

	try
	{
		numbers.enqueue(2.5f);
		numbers.enqueue(3.14f);
		numbers.enqueue(8.9f);
		numbers.enqueue(9.99f);
		numbers.enqueue(14.8f);
		numbers.enqueue(20.8f); 

		for (size_t i = 0; i < 6; ++i)
			cout << "Removed: " << numbers.dequeue() << endl; 
		cout << endl; 

		numbers.enqueue(8.8f); 
		numbers.enqueue(9.1f); 
		
		cout << "First: " << numbers.first() << endl; 
		cout << "Last: " << numbers.last() << endl; 
	}
	catch (const Error& e)
	{
		cerr << e.what() << endl; 
	}
	
	return 0; 
}


template <typename T>
Queue<T>::Queue(int size) : size(size+1), front(0), back(0) {
	if (size <= 0) {
		throw Error("Queue size must be greater than 0!");
	}
	data = new T[size+1];
}

template<typename T> 
Queue<T>::~Queue()
{
	delete[] this->data; 
}

template <typename T>
Queue<T>::Queue(const Queue& other) {
	size = other.size;
	front = other.front;
	back = other.back;
	data = new T[size];
	for (int i = front; i != back; i = (i + 1) % size) {
		data[i] = other.data[i];
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this != &other) {
		delete[] data;
		size = other.size;
		front = other.front;
		back = other.back;
		data = new T[size];
		for (int i = front; i != back; i = (i + 1) % size) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template<typename T> 
bool Queue<T>::isEmpty() const
{
	return front == back; 
}

template<typename T> 
bool Queue<T>::isFull() const
{
	return (back + 1) % size == front;
}

template<typename T>
void Queue<T>::enqueue(T elem)
{
	if (isFull())
		throw Error("The Queue is full!"); 

	data[back] = elem; 
	back = (back + 1) % size;
}

template<typename T> 
T Queue<T>::dequeue()
{
	if (isEmpty())
		throw Error("Empty Queue!"); 

	T elem = data[front];
	front = (front + 1) % size;
	return elem; 
}

template<typename T> 
T Queue<T>::first() const 
{
	if (isEmpty())
		throw Error("Empty Queue!");
	return data[front]; 
}

template<typename T> 
T Queue<T>::last() const
{
	if (isEmpty())
		throw Error("Empty Queue!");
	return data[(back-1+size)%size];
}