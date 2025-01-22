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
		cout << "Queue first: " << numbers.first() << endl;
		cout << "Queue last: " << numbers.last() << endl;
	}
	catch (const Error& e)
	{
		cerr << e.what() << endl; 
	}
	
	return 0; 
}


template <typename T>
Queue<T>::Queue(int size) : size(size), front(-1), back(-1) {
	if (size <= 0) {
		throw Error("Queue size must be greater than 0!");
	}
	data = new T[size];
}

template<typename T> 
Queue<T>::~Queue()
{
	delete[] this->data; 
}

template <typename T>
Queue<T>::Queue(const Queue& other) {
	copyFrom(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this != &other) { 		
		delete[] data;    
		copyFrom(other); 
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
	return back == size - 1; 
}

template<typename T>
void Queue<T>::enqueue(T elem)
{
	if (isFull())
		throw Error("The Queue is full!"); 
	this->data[++this->back] = elem; 
}

template<typename T> 
T Queue<T>::dequeue()
{
	if (isEmpty())
		throw Error("Empty Queue!"); 

	T elem = data[++this->front]; 
	if (front == back)
		front = back = -1; 
	return elem; 
}

template<typename T> 
T Queue<T>::first() const 
{
	if (isEmpty())
		throw Error("Empty Queue!");
	int idx = this->front;
	return data[++idx]; 
}

template<typename T> 
T Queue<T>::last() const
{
	if (isEmpty())
		throw Error("Empty Queue!");
	return data[this->back]; 
}