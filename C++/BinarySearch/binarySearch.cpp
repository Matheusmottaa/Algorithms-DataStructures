#include <iostream> 

using namespace std; 

void binarySearch(int *array, int element, int length)
{ 
  int begin = 0; 
  int end = length - 1; 

  while(begin <= end)
  { 
    int mid = (begin+end)/2; 
    int guess = array[mid]; 

    if(guess == element)
    { 
      cout << "Element found at: " << mid << " th index"<< endl; 
      return; 
    }else if(guess > element)
    { 
      end = mid - 1; 
    }else if(guess < element)
    { 
      begin = mid + 1; 
    }
  }
  cout << "Element Not found!" << endl; 
  return ; 
}

int main()
{ 
  int array[] = {1,2,3,10,12,20,31,33,48}; 
  int length = sizeof(array)/sizeof(array[0]); 
  binarySearch(array,10,length); 
  binarySearch(array, 48, length); 
  binarySearch(array,4,length); 
  return 0; 
}

/* 
  Time Complexity O(log n). 
  Space Complexity O(1). 

*/