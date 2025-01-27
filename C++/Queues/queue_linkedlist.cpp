#include <iostream>
#include <stdexcept>

using namespace std;

class Error : public runtime_error {
public:
    explicit Error(const string& message) : runtime_error(message) {}
};

template<typename T>
class Queue {
private:
    template<typename T>
    struct Node {
        T data;
        Node<T>* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node<T>* first;
    Node<T>* last;

    void clear();
    void copyFrom(const Queue<T>&); 

public:
    Queue();                        
    ~Queue();
    Queue(const Queue<T>&);
    Queue<T>& operator=(const Queue<T>&);

    void enqueue(T);
    T dequeue();
    T front();
    T end();
    bool isEmpty();
    bool isFull();
};

int main() {
    Queue<string> bankLine;

    try
    {
        bankLine.enqueue("Amanda");
        bankLine.enqueue("Harvey");
        bankLine.enqueue("Matthew");
        bankLine.enqueue("Luisa");

        cout << "First: " << bankLine.front() << endl;
        cout << "Last: " << bankLine.end() << endl;

        cout << endl;

        for (int i = 0; i < 4; ++i)
            cout << "Remove from the line: " << bankLine.dequeue() << endl;

        cout << endl;
        cout << "Is the bank line empty? " << (bankLine.isEmpty() ? "Yes\n" : "No\n");

    }
    catch (Error e)
    {
        cerr << e.what() << endl; 
    }
    
    return 0;
}

template<typename T>
Queue<T>::Queue() : first(nullptr), last(nullptr) {}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : first(nullptr), last(nullptr) 
{
    copyFrom(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) 
{
    if (this != &other) 
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
void Queue<T>::enqueue(T elem) 
{
    Node<T>* data = new Node<T>(elem);
    if (!data)
        throw Error("Queue is full!\n");

    if (first)
    {
        last->next = data;
        last = data;
    }
    else
        first = last = data;
 
}

template<typename T>
T Queue<T>::dequeue()
{
    if (first == nullptr)
        throw Error("Empty Queue!\n");

    T elem = first->data;
    Node<T>* temp = first;
    first = first->next;
    delete temp;
    return elem;
}

template<typename T>
T Queue<T>::front() 
{
    if (!first) throw Error("Empty Queue!\n");
    return first->data;
}

template<typename T>
T Queue<T>::end()
{
    if (!first) throw Error("Empty Queue!\n");
    return last->data;
}

template<typename T>
bool Queue<T>::isFull()
{
    try
    {
        Node<T>* temp = new Node<T>(T());
        delete temp;
        return false;
    }
    catch (const std::bad_alloc&)
    {
        return true;
    }
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return first == nullptr;
}

template<typename T>
void Queue<T>::clear()
{
    Node<T>* current = first;
    while (current != nullptr) 
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    first = last = nullptr;
}

template<typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
    Node<T>* current = other.first;
    while (current != nullptr)
    {
        enqueue(current->data);
        current = current->next;
    }
}