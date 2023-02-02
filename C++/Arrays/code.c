#include <stdio.h> 
#include <stdlib.h> 

void showArray(int *A, int size)
{
    for(int i=0;i<size;i++)
    { 
        printf("&A[%d] = %p, (A+%i) = %p\n", i, &A[i], i, (A+i));
        printf("A[%d] = %d, *(A+%d) = %d\n", i, A[i], i, *(A+i)); 
    }
}

void showMatrix(int (*m)[3], int n_rows, int n_columns)
{ 
    for(int i=0;i<n_rows;i++)
    {
        printf("(m+%d) = %p, &m[%d] = %p\n", i, (m+i), i, &m[i]); 
        for(int j=0;j<n_columns;j++)
        { 
            printf("((m+%d) + %d) = %p, &m[%d][%d] = %p, (*(m+%d)+%d) = %p\n", i, j, ((m+i)+j), i, j, &m[i][j], i, j, (*(m+i)+j)); 
            printf("*(*(m+%d)+%d) = %d, m[%d][%d] = %d\n\n", i, j, *(*(m+i)+j), i, j, m[i][j]); 
        }
    }
}

int main(int argc, char *argv[])
{ 
    int A[5] = {8,3,5,8,10}; 
    int Asize = sizeof A / sizeof(int); 

    // M é uma abstração para o  endereço de memória de um array de 1D de 3 inteiros, ou seja  (*m)[3]. 
    /* 
        P = Ponteiro para um array de 1D de 3 inteiros 
        *P = Ponteiro para um inteiro. 
        **P = conteudo daquela posicao de memória. 
    
    */
    int M[2][3] = {{2,3,4}, {11,20,37}}; 
    int (*P)[3] = M; 
    int Msize = sizeof M / sizeof(int); 
    showMatrix(M, 2, 3); 

    // printf("&M[0][2] = %p\n", &M[0][2]); 
    // printf("*M+2 = %p, *(*M+2) = %d\n", *M+2, *(*M+2)); 

    printf("Clean screen? (y/n): "); 
    char opt; 
    scanf("%c", &opt); 

    opt == 'y' || opt == 'Y' ? system("clear") : putchar('\n'); 

    printf("*M + 0 = %p\n", *M+0); 
    printf("&M[0] = %p\n", &M[0]); 
    printf("&M[0][0] = %p\n", &M[0][0]); 
    printf("M = %p\n", M); 
    printf("*M = %p\n", *M); 
    putchar('\n'); 
    putchar('\n'); 

    // Imprime endereço base do array unidimensional que começa na linha M[0] 
    printf("*M = %p, M[0] = %p, &M[0][0] = %p\n", *M, M[0], &M[0][0]); 
    putchar('\n'); 
    // Imprime endereço base do array unidimensional que começa na linha M[1] 
    printf("&M[1] = %p, &M[1][0] = %p, *(M+1) = %p, *(M+1)+0 = %p, M+1 = %p\n", &M[1], &M[1][0], *(M+1), *(M+1)+0, M+1); 
    printf("*(*M+0) = %d, **M = %d\n", *(*M+0), **M); 
    
    

    return 0; 
}