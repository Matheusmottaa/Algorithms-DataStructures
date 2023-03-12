#include <stdio.h> 
#include "arrayADT.h"

int main()
{
    Array *v = create(); 

    printf("Capacity of array = %d\n", capacity(v)); 
    add(v,2); 
    add(v,5); 
    add(v,3);
    add(v,10);
    add(v,19); 
    add(v,32); 

    printf("All elements of array: \n"); 
    display(v); 
    putchar('\n'); 

    printf("Insert an elment at index 4\n"); 
    insert(v,4, 77); 
    display(v); 

    putchar('\n'); 
    printf("Delete an element at index 2\nElement has been deleted = %d\n", delete(v,2)); 
    printf("Length of V = %d\n", size(v)); 
    display(v); 

    putchar('\n'); 
    printf("remove the last item of array: %d\n", pop(v)); 
    display(v); 

    putchar('\n'); 
    printf("add an element at the beginning of array\n"); 
    unshift(v,44); 
    display(v); 
    
    putchar('\n'); 
    printf("Current length of array: \n"); 
    printf("Length = %d\n", size(v)); 

    putchar('\n'); 
    printf("Remove first element: %d\n", shift(v)); 
    display(v); 
    printf("Length = %d\n", size(v)); 

    putchar('\n'); 
    puts("Reversing the list\n"); 
    reverse(v); 
    display(v); 

    putchar('\n'); 
    printf("Left shift operation:\n"); 
    leftShift(v); 
    display(v); 

    putchar('\n'); 
    printf("Sum of all elements = %d\n", sum(v,size(v)-1)); 

    Array *v2 = create(); 
    add(v2, 101); 
    add(v2, 120); 
    add(v2,410);
    add(v2,127); 

    putchar('\n'); 
    printf("Mergin arrays\n"); 
    Array *arr = merge(v, v2); 
    display(arr); 
    printf("Arr length = %d\n", size(arr)); 

    destroy(&v2); 
    destroy(&v); 
    destroy(&arr); 

    return 0; 
}