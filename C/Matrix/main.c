#include <stdio.h> 
#include <stdlib.h> 

#define Row 2
#define Column 3 

void loadValues(int **m)
{
    int count = 1; 

    for(int i=0;i<Row;i++)
    {
        for(int j=0;j<Column;j++)
        {
            m[i][j] = count++ * 3; 
        }
    }
}

void print(const int **m)
{
    for(int i=0;i<Row;i++)
    {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]); 
        printf("m+%d = %p, *(m+%d) = %p\n", i, m+i, i, *(m+i)); 
        for(int j=0;j<Column; j++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
            printf("*(m+%d)+%d = %p, *(*(m+%d)+%d) = %d\n", i, j, *(m+i)+j, i,j,*(*(m+i)+j)); 
            putchar('\n'); 
        }
        puts("\n"); 
    }
}

int ***create_M3D()
{
    int ***m = (int***)calloc(2,sizeof(int**));
    for(int k=0;k<2;k++)
    {
        *(m+k) = (int**)calloc(2,sizeof(int*)); 
        for(int i=0;i<2;i++)
        {
            *(*(m+k)+i) = (int*)calloc(3,sizeof(int)); 
        }
    } 
    return m; 
}

void loadValues_M3D(int ***m)
{
    int count = 1; 
    for(int k=0;k<2;k++)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                m[k][i][j] = count++ * 3; 
            }
        }
    }
}

void print_3D(int ***m)
{
    for(int k=0;k<2;k++)
    {
        printf("&m[%d] = %p, m[%d] = %p\n\n", k,  &m[k], k, m[k]); 
        printf("m + %d = %p, *(m+%d) = %p\n\n", k, m+k, k, *(m+k)); 
        for(int i=0;i<2;i++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %p\n\n", k, i, &m[k][i], k, i, m[k][i]);
            printf("*(m+%d)+%d = %p, *(*(m+%d)+%d) = %p\n\n", k, i, *(m+k)+i, k, i, *(*(m+k)+i)) ; 
            puts("\n"); 
            for(int j=0;j<3;j++)
            {
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k,i,j, &m[k][i][j], k, i, j, m[k][i][j]); 
                printf("*(*(m+%d)+%d)+%d = %p, *(*(*(m+%d)+%d)+%d) = %d\n", k, i, j, *(*(m+k)+i)+j, k, i, j, *(*(*(m+k)+i)+j));    
                putchar('\n'); 
            }
            puts("\n"); 
        }
        puts("\n"); 
    }
}

int main(int argc, char *argv[])
{
    int **m = (int**)malloc(Row*sizeof(int*)); 

    for(int i=0;i<Row;i++)
    {
        *(m+i) = (int*)calloc(Column,sizeof(int)); 
    }

    loadValues(m); 
        
    print(m); 

    for(int i=0;i<Row;i++)
    {
        free(*(m+i)); 
    }
    free(m); 


    int ***m3D = create_M3D(); 

    loadValues_M3D(m3D); 

    putchar('\n'); 
    puts("************************3D MATRIX************************\n"); 

    print_3D(m3D); 


    for(int k=0;k<2;k++)
    {
        for(int i=0;i<2;i++)
        {
            free(*(*(m3D+k)+i)); 
        }
        free(*(m3D+k)); 
    }

    free(m3D); 

    return 0; 
}