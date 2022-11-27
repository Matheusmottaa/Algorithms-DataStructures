#include <iostream> 
#include <cstdlib> 

using namespace std; 

void example1(); 
void example2(); 


int main()
{ 

  // same as  int* array = (int*) malloc(sizeof(int)*5) in C language
  int *array = new int[5]; // allocated array in heap  

  cout << "Enter with some values: " << endl; 
  for(int i=0;i<5;i++)
    cin >> array[i]; 

  system("clear"); 
  
  cout << "Your choose of values is : " << endl; 
  for(int i=0;i<5;i++)
    cout << "array[" << i << "] = " << array[i] << endl; 


  // same as free(array) in C language. 
  delete[] array; // free the memory on the heap (Deallocation)

  // Increase a size of an array
  
  int* p = new int[5]; 

  p[0] = 2; 
  p[1] = 4; 
  p[2] = 6; 
  p[3] = 8; 
  p[4] = 10;

  int* q = new int[10]; 

  for(int i=0; i<5;i++)
    q[i] = p[i]; 

  delete[] p; 

  p = q; 

  q = NULL; 

  for(int i=0;i<10;i++)
    cout << p[i] << endl; 


  // 2D Arrays

  int vector[3][4] = {{2,3,4,5},{10,11,12,13},{20,30,40,50}}; 

  for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
      cout << "vector["<< i << "][" << j << "] = " << vector[i][j] << endl; 

  return 0; 
}

// 2D arrays in Heap. C language
void example1()
{ 
    int *a[3];

  a[0] = (int*) malloc(4*sizeof(int)); 
  a[1] = (int*) malloc(4*sizeof(int)); 
  a[2] = (int*) malloc(4*sizeof(int)); 

  int i,j; 

  int v= 2; 

  for(i=0;i<3;i++){
    for(j=0;j<4;j++)
      a[i][j] = (j+v)*2; 
    v++; 
  }

  for(i=0;i<3;i++){
    for(j=0;j<4;j++)
      printf("a[%d][%d] = %d\n", i,j,a[i][j]); 
  }

  
}

// 2d arrays in heap 
void example2()
{ 
  int *a[3]; 
  
  a[0] = new int[4]; 
  a[1] = new int[4]; 
  a[2] = new int[4]; 

  int v= 2; 

  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++)
      a[i][j] = (j+v)*2; 
    v++; 
  }

  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++)
      printf("a[%d][%d] = %d\n", i,j,a[i][j]); 
  }

}