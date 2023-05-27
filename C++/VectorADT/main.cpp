#include <iostream> 

#define MINCAPACITY 10
#define GROWFACTOR 2

using namespace std; 

class IllegalOperation{ 
    private: 
        string message; 
    public: 
        IllegalOperation(string message)
        {
            this->message = message; 
        }

        void outputMessage()
        {
            cout << message << endl; 
        }
}; 

template<class T>
class Vector{ 
    private: 
        int capacity; 
        size_t length; 
        T *data; 
        void resize(); 
        void swap(T *, T *); 
    public: 
        Vector(); 
        ~Vector(); 
        bool isFull(); 
        bool isEmpty(); 
        int size(); 
        T get(int index);
        void set(int index, T elem); 
        void display(); 
        void pushBack(T elem); 
        void pushFront(T elem); 
        void insertAt(int index, T elem); 
        T removeBack(); 
        T removeFront(); 
        T removeAt(int index); 
        bool isSorted(); 
        int find(T elem); 
        int binarySearch(T elem); 
        void reverse(); 
}; 


int main()
{
    try{ 

        Vector<int> list; 
        list.pushBack(2); 
        list.pushBack(3); 
        list.pushBack(8); 
        list.pushBack(10); 
        list.pushBack(17);

        list.display(); 

    }catch(IllegalOperation e)
    {
        e.outputMessage(); 
    }

    return 0; 
}

template<class T> 
Vector<T>::Vector()
{
    capacity = MINCAPACITY;
    length = 0; 
    data = new T[capacity]; 
}

template<class T>
Vector<T>::~Vector()
{
    delete[] data; 
}

template<class T>
int Vector<T>::size()
{
    return length; 
}

template<class T>
bool Vector<T>::isEmpty()
{
    return length == 0; 
}

template<class T>
bool Vector<T>::isFull()
{
    return capacity == length; 
}

template<class T>
void Vector<T>::swap(T *x, T *y)
{
    T aux = *x; 
    *x = *y; 
    *y = aux; 
}

template<class T>
void Vector<T>::resize()
{
    if(isFull())
    {
        capacity *= GROWFACTOR; 
        T *temp = new T[capacity]; 
        for(int i=0; i<length; i++)
            temp[i] = data[i]; 
        delete []data; 
        data = temp; 
        temp = nullptr; 
    }
}

template<class T>
void Vector<T>::set(int index, T elem)
{
    if(index<0 || index>=length)
    {
        throw IllegalOperation("Invalid Index"); 
    }
    data[index] = elem; 
}

template<class T>
T Vector<T>::get(int index)
{
    if(index<0 || index>=length)
    {
        throw IllegalOperation("Invalid Index"); 
    }
    return data[index]; 
}

template<class T>
void Vector<T>::display()
{
    for(int i=0; i<length; i++)
    {
        if(i==length-1)
            cout << data[i];
        else
            cout << data[i] << ", ";  
    }
    cout << endl; 
}

template<class T>
void Vector<T>::pushBack(T elem)
{
    resize(); 
    data[length++] = elem; 
}

template<class T>
void Vector<T>::pushFront(T elem)
{
    resize(); 
    for(int i=length-1; i>=0; i--)
        data[i+1] = data[i]; 
    data[0] = elem; 
    length++; 
}

template<class T> 
void Vector<T>::insertAt(int index, T elem)
{
    if(index<0 || index>length)
    {
        throw IllegalOperation("Invalid Index"); 
    }
    resize(); 
    for(int i=length-1; i>=index; i--)
        data[i+1] = data[i]; 
    data[index] = elem; 
    length++; 
}

template<class T>
T Vector<T>::removeBack()
{
    if(isEmpty())
    {
        throw IllegalOperation("Empty List"); 
    }
    const T elem = data[length-1]; 
    length--; 
    return elem; 
}

template<class T>
T Vector<T>::removeFront()
{
    if(isEmpty())
    {
        throw IllegalOperation("Empty List"); 
    }
    const T elem = data[0]; 
    for(int i=1; i<length; i++)
        data[i-1] = data[i]; 
    length--; 
    return elem; 
}

template<class T>
T Vector<T>::removeAt(int index)
{
    if(index<0 || index>=length)
    {
        throw IllegalOperation("Invalid index"); 
    }
    const T elem = data[index]; 
    for(int i=index+1; i<length; i++)
        data[i-1] = data[i]; 

    length--; 
    return elem; 
}

template<class T>
int Vector<T>::find(T elem)
{
    for(int i=0; i<length; i++)
        if(elem == data[i])
            return i; 
    return -1; 
}

template<class T>
bool Vector<T>::isSorted()
{
    for(int i=0; i<length-1; i++)
        if(data[i] > data[i+1])
            return false;
    return true; 
}

template<class T>
int Vector<T>::binarySearch(T elem)
{
    if(!isSorted())
    {
        throw IllegalOperation("List is not sorted!"); 
    }
    int begin = 0; 
    int end = length-1; 
    while(begin<=end)
    {
        int mid = (begin+end)/2; 
        if(data[mid] == elem)
            return mid; 
        else if(data[mid] > elem)
            end = mid - 1; 
        else 
            begin = mid + 1; 
    }
    return -1; 
}

template<class T>
void Vector<T>::reverse()
{
    for(int i=0, j=length-1; i<j; i++, j--)
    {
        swap(data+i, data+j); 
    }
}