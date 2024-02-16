#include <iostream> 
#include <vector>

using namespace std; 

class Exception
{ 
private: 
    string message; 
public: 
    Exception(string message)
    {
        this->message = message; 
    }

    string getMessage()
    {
        return this->message; 
    }
}; 


template<typename T> 
struct Node 
{ 
    Node *next; 
    T data; 
    Node(T data)
    {
        this->data = data; 
    }
}; 

template<typename T>
class LinkedList 
{ 
private: 
    Node<T> *head; 
    size_t length; 

public: 
    LinkedList();
    ~LinkedList();
    void display(); 
    void createFromVector(vector<T>); 
    void push_front(T); 
    void push_back(T); 
    T remove_front(); 
    T remove_back(); 
    Node<T> *get(int); 
    void set(int, T );
    void insert_at(int, T);
    T remove_at(int); 
    size_t size(); 

}; 


int main(int argc, char *argv[])
{

    try 
    {
        vector<string> names; 
        names.push_back("Goku"); 
        names.push_back("Vegeta"); 
        names.push_back("Naruto"); 
        names.push_back("Kakashi");

        LinkedList<string> listNames; 
        listNames.createFromVector(names); 
        listNames.push_back("Ichigo"); 
        cout << "List of characters: \n\n"; 
        listNames.display(); 

        cout << endl; 

        cout << "List of numbers: \n\n"; 
        vector<int> numbers; 
        numbers.push_back(2); 
        numbers.push_back(3); 
        numbers.push_back(4); 
        numbers.push_back(5);

        LinkedList<int> listNumbers;
        listNumbers.createFromVector(numbers); 
        listNumbers.push_front(1); 
        listNumbers.display(); 
    }
    catch(Exception e)
    {
        cerr << e.getMessage() << endl; 
    }
}


template<typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr; 
    this->length = 0; 
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = this->head; 
    Node<T> *prev = nullptr; 
    while(current != nullptr)
    {
        prev = current; 
        current = current->next; 
        delete prev; 
    }
}

template<typename T>
void LinkedList<T>::display()
{
    Node<T> *current = this->head; 
    while(current != nullptr)
    {
        cout << current->data << endl; 
        current = current->next; 
    }
}

template<typename T> 
void LinkedList<T>::createFromVector(vector<T> v)
{
    Node<T> *first = nullptr, *temp = nullptr, *current = nullptr; 
    first = new Node<T>(v.at(0)); 
    current = first; 
    for(int i=1;i<v.size(); i++)
    {
        temp = new Node<T>(v.at(i)); 
        current->next = temp; 
        current = temp; 
    }
    this->head = first; 
    this->length = v.size(); 
}

template<typename T>
void LinkedList<T>::push_front(T elem)
{
    if(this->head == nullptr)
    {
        Node<T> *newNode = new Node<T>(elem); 
        this->head = newNode; 
        this->length++; 
    }
    else 
    {
        Node<T> *newNode = new Node<T>(elem); 
        newNode->next = this->head; 
        this->head = newNode; 
        this->length++; 
    }
}

template<typename T>
void LinkedList<T>::push_back(T elem)
{
    if(this->head == nullptr)
    {
        Node<T> *newNode = new Node<T>(elem); 
        this->head = newNode; 
        this->length++; 
    }
    else 
    {
        Node<T> *current = this->head; 
        while(current->next != nullptr)
        {
            current = current->next; 
        }
        Node<T> *newNode = new Node<T>(elem); 
        current->next = newNode; 
        this->length++; 
    }
}

template<typename T>
T LinkedList<T>::remove_front()
{
    if(this->head == nullptr)
    {
        throw Exception("Error: The list is empty!");
    }
    Node<T> *removedNode = this->head; 
    this->head = removedNode->next; 
    const T deleteElement = removedNode->data; 
    delete removedNode; 
    this->length--; 
    return deleteElement; 
}

template<typename T>
T LinkedList<T>::remove_back()
{
    if(this->head == nullptr)
    {
        throw Exception("Error: The list is empty!"); 
    }
    
    if(this->head->next == nullptr)
    {
        const T removedElement = this->head->data; 
        delete this->head; 
        this->head = nullptr; 
        this->length--; 
        return removedElement; 
    }

    Node<T> *current = this->head; 
    while(current->next->next != nullptr)
    {
        current = current->next; 
    }
    Node<T> *removedNode = current->next; 
    current->next = nullptr; 
    const T removedElement = removedNode->data; 
    delete removedNode; 
    this->length--; 
    return removedElement; 
}

template<typename T>
Node<T> * LinkedList<T>::get(int idx)
{
    if(idx>=0 && idx<this->length)
    {
        Node<T> *current = this->head; 
        size_t i = 0; 
        while(i!=idx)
        {
            current = current->next; 
            i++; 
        }
        return current; 
    }
    else 
    {
        throw Exception("Error: Invalid index!"); 
    }
}

template<typename T>
void LinkedList<T>::set(int idx, T elem)
{
    try
    { 
        Node<T> *node = get(idx); 
        node->data = elem; 
    }
    catch(Exception e)
    {
        cerr << e.getMessage() << endl; 
    }
}

template<typename T>
void LinkedList<T>::insert_at(int idx, T elem)
{

    if(idx == 0)
    {
        push_front(elem); 
        return; 
    }

    try
    {
        Node<T> *prev = get(idx-1); 
        Node<T> *newNode = new Node<T>(elem); 
        newNode->next = prev->next; 
        prev->next = newNode; 
        this->length++; 
    }
    catch(Exception e)
    {
        throw e; 
    }
    
}

template<typename T>
T LinkedList<T>::remove_at(int idx)
{
    if(idx == 0)
    {
        return this->remove_front(); 
    }
    try
    {
        Node<T> *prev = get(idx-1); 
        Node<T> *removedNode = prev->next; 
        prev->next = removedNode->next; 
        const T data = removedNode->data; 
        delete removedNode; 
        this->length--; 
        return data; 
    }
    catch(Exception e)
    {
        throw e; 
    }
    
}

template<typename T>
size_t LinkedList<T>::size()
{
    Node<T> *current = this->head; 
    size_t i = 0; 
    while(current!=nullptr)
    {
        i++; 
        current = current->next; 
    }
    return i; 
}