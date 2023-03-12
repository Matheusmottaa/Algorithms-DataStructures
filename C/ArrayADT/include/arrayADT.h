#ifndef ARRAY_ADT
#define ARRAY_ADT

typedef struct Array_ Array; 

Array *create(); 
void destroy(Array **p); 
int capacity(const Array *arr);
int size(const Array *arr);  
void display(const Array *arr); 
void add(Array *arr, int elem); 
void insert(Array *arr, int index, int elem); 
int delete(Array *arr, int index);
void set(Array *arr, int index, int value); 
int pop(Array *arr); 
void unshift(Array *arr, int elem); 
int shift(Array *arr); 
int get(const Array *arr, int index); 
int search(Array *arr, int elem); 
int binarySearchRecursive(const Array *arr, int begin, int end, int elem); 
void reverse(Array *arr); 
int sum(const Array *arr, int n); 
int max(const Array *arr); 
int min(const Array *arr); 
short isSorted(const Array *arr);
Array  *merge(const Array *arr, const Array *arr2);  
void leftShift(Array *arr); 
// Insert an element in a sort array. 
void insertSortArr(Array *arr, int elem); 


#endif