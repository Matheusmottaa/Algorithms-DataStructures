#include <stdio.h> 
#include <stdlib.h> 

int binarySearch(int *, int, int, int); 

int factorial(int n); 

int simpleSearch(int*, int, int, int); 

int main(int argc, char *argv[])
{
    int array[6] = {4,8,1,20,18,45}; 
    int length = sizeof array / sizeof array[0]; 

    int vector[9] = {3,7,10,20,31,38,89,90,100}; 
    int size = sizeof vector / sizeof(int); 

    printf("searching for element \"18\" in the list, position: %d\n", simpleSearch(array, 18, 0, length)); 

    printf("Searching for \"38\" in the list, postion: %d\n", binarySearch(vector, 38, 0, size-1)); 

    printf("6! = %d\n", factorial(6)); 

    return 0; 
}

int binarySearch(int *array, int elem, int begin, int end)
{
    if(begin<=end)
    {
        int mid = (begin+end)/2; 
        if(*(array+mid) == elem)
            return mid; 
        else if(*(array+mid) > elem)
            return binarySearch(array, elem, begin, mid-1); 
        else 
            return binarySearch(array, elem, mid+1, end); 
    }
    return -1; 
}

int factorial(int n)
{
    if(n>1)
        return n * factorial(n-1); 
    return 1; 
}

int simpleSearch(int *arr, int elem, int begin, int size)
{
    if(begin<=size-1)
    {
        if(arr[begin] == elem)
            return begin; 
        else 
            return simpleSearch(arr, elem, begin+1, size); 
    }
    return -1; 
}
