#include "arrayADT.h"
#include <stdio.h> 
#include <stdlib.h>

typedef struct Array_{ 
    int *v; 
    int capacity; 
    int length; 
}Array; 

Array *create()
{
    Array *arr = (Array *)calloc(1,sizeof(Array)); 
    arr->capacity = 10; 
    arr->v = (int *)calloc(arr->capacity,sizeof(int)); 
    arr->length = 0;
    return arr; 
}

void destroy(Array **p)
{
    free((*p)->v); 
    free(*p); 
    *p = NULL; 
}

int capacity(const Array *arr)
{
    return arr->capacity; 
}

int size(const Array *arr)
{
    return arr->length; 
}

void display(const Array *arr)
{
    for(int i=0;i<arr->length;i++)
    {
        printf("%d\n", arr->v[i]); 
    }
}

void add(Array *arr, int elem)
{
    arr->v[arr->length] = elem; 
    arr->length++; 
}

void insert(Array *arr, int index, int elem)
{
    if(index<0 || index>arr->length || arr->length == arr->capacity) return; 
    for(int i=arr->length;i>index;i--)
    {
        arr->v[i] = arr->v[i-1]; 
    }
    arr->v[index] = elem; 
    arr->length++; 
}

int delete(Array *arr, int index)
{
    if(index<0 || index>=arr->length) 
    {
        fprintf(stderr, "Invalid index\n"); 
        exit(1); 
    }
    const int elem = arr->v[index]; 
    for(int i=index;i<arr->length-1;i++)
    {
        arr->v[i] = arr->v[i+1]; 
    }
    arr->v[arr->length-1] = 0; 
    arr->length--; 
    return elem; 
}

int pop(Array *arr)
{
    const int elem = arr->v[arr->length-1]; 
    arr->v[arr->length-1] = 0; 
    arr->length--; 
    return elem; 
}

void set(Array *arr, int index, int value)
{
    if(index<0||index>=arr->length) return; 
    arr->v[index] = value; 
}

void unshift(Array *arr,int elem)
{
    if(arr->length == arr->capacity) return; 
    for(int i=arr->length-1;i>=0;i--)
    {
        arr->v[i+1] = arr->v[i]; 
    }
    arr->v[0] = elem; 
    arr->length++;
}

int shift(Array *arr)
{
    const int elem = arr->v[0]; 

    for(int i=0;i<arr->length-1;i++)
    {
        arr->v[i] = arr->v[i+1]; 
    }
    arr->v[arr->length-1] = 0; 
    arr->length--; 
    return elem; 
}

int get(const Array *arr, int index)
{
    if(index>=arr->length || index<0) 
    {
        fprintf(stderr, "Invalid index\n"); 
        exit(1); 
    }
    
    return arr->v[index]; 
}

void swap(int *x, int *y)
{
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int search(Array *arr, int elem)
{
    if(arr->length==0) 
        return -1; 
    if(arr->v[0] == elem)
        return 0; 
    for(int i=0;i<arr->length;i++)
    {
        if(arr->v[i] == elem)
        {
            // Transposition
            swap(&arr->v[i], &arr->v[i-1]); 
            return i-1; 
        }
            
    }
    return -1; 
}

int binarySearchRecursive(const Array *arr, int begin, int end, int elem)
{
    if(begin<=end){ 
        int mid = (begin+end)/2; 
        if(arr->v[mid] == elem)
            return mid; 
        else if(arr->v[mid] > elem)
            return binarySearchRecursive(arr, begin, mid-1, elem); 
        else 
            return binarySearchRecursive(arr, mid+1,end, elem); 
    }
    return -1; 
}

void reverse(Array *arr)
{
    if(arr->length == 0) return ; 

    for(int i=arr->length-1, j=0;i>j;i--,j++)
        swap(&arr->v[j],&arr->v[i]); 
}

int sum(const Array *arr, int length)
{
    if(length>=0){ 
        return sum(arr, length-1) + arr->v[length]; 
    }
    return 0; 
}

int max(const Array *arr)
{
    int max = arr->v[0]; 
    for(int i=0;i<arr->length;i++)
    {
        if(arr->v[i] > max)
        {
            max = arr->v[i]; 
        }
    }
    return max; 
}

int min(const Array *arr)
{
    int min = arr->v[0]; 
    for(int i=0;i<arr->length;i++)
    {
        if(min > arr->v[i])
            min = arr->v[i]; 
    }
    return min; 
}

short isSorted(const Array *arr)
{
    for(int i=0;i<arr->length-1;i++)
    {
        if(arr->v[i] > arr->v[i+1])
            return 0; 
    }
    return 1; 
}

Array *merge(const Array *arr1, const Array *arr2)
{
    Array *arr = (Array *)calloc(1,sizeof(Array)); 
    arr->capacity = arr1->capacity + arr2->capacity; 
    arr->v = (int*)calloc(arr->capacity,sizeof(int)); 

    for(int i=0;i<arr1->length;i++)
        arr->v[i] = arr1->v[i]; 

    for(int i=arr1->length, j=0;j<arr2->length;j++, i++)
    {
        arr->v[i] = arr2->v[j]; 
    }

    arr->length = arr1->length + arr2->length; 

    return arr; 
}

void leftShift(Array *arr)
{
    if(arr->length == 0) return ;  
    const int deleteEl = arr->v[0]; 
    for(int i=0;i<arr->length-1;i++)
    {
        arr->v[i] = arr->v[i+1]; 
    }
    // Rotate the element that would be deleted
    arr->v[arr->length-1] = deleteEl; 
}

void insertSortArr(Array *arr, int elem)
{
    if(arr->capacity == arr->length) return; 

    register int i = arr->length-1; 

    while(i>=0 && arr->v[i] > elem)
    {
        arr->v[i+1] = arr->v[i]; 
        i--; 
    }
    arr->v[i+1] = elem;
    arr->length++; 
}
