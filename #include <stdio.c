#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h> 
#include <malloc.h> 
#include <string.h>

void CreateMatrix(int** matrix, int n, int m);
void PrintMatrix(int** matrix, int n, int m);
int** TransposeMatrix(int** matrix, int n, int m);
int** AddMatrix(int** matrix1, int n_1, int m_1, int** matrix2, int n_2, int m_2);
int** MultiMatrix( int ** matrix1, int n_1, int m_1, int**matrix2, int n_2, int m_2);
int** PowerMatrix( int** matrix, int n, int m, int power ); 

int main()
{
    int n_1, n_2, m_1, m_2; 
    scanf("%d %d", &n_1, &m_1);
    int** matrix1; 
    matrix1 = (int**)malloc(n_1*sizeof(int*));
    for (int i = 0; i < n_1; i++) {
        matrix1[i] = (int*)malloc(m_1 * sizeof(int));
    }
    CreateMatrix(matrix1, n_1, m_1);
    printf("A:\n");
    PrintMatrix(matrix1, n_1, m_1); 
    int sum[100]={0};
    
    for(int j =0; j<m_1; j++)
    {           
        sum[j] += SumMatrix(matrix1, n_1, m_1, j);
    }
    int min_sum=INT_MAX; 
    int arrcheck[100]={0}; 
    for(int j =0; j< m_1; j++)
    {   
        if(sum[j] < min_sum) min_sum = sum[j];
       
    } 
    for(int j =0; j< m_1; j++)
    {   
       if(sum[j] == min_sum)  arrcheck[j]++; 
    }
    for(int j =0; j< 10; j++)
    {   
       printf("%d ",  sum[j]);  
    }
    for (int i = 0; i < m_1; i++)
    {
                for (int j = i + 1; j < m_1; j++)
                {
                    if (sum[i] > sum[j])
                    {
                        temp = sum[i];
                        sum[i] = sum[j];
                        sum[j] = temp;
                    }                   
                }            
    }
    for(int j=0; j<m_1; j++)
    {
        if(arr==){

        for(int i =0; i<n_1; i++) 
        {
            if(arrcheck[i]==1) printf("%6d", matrix1[j][i]);
        }
        }
    }
    return 0; 
}

void CreateMatrix(int** matrix, int n, int m) {
  int number = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}
void PrintMatrix(int** matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%6d", matrix[i][j]);
    }
    printf("\n");
  }
}
int SumMatrix(int** matrix, int n, int m, int i) {
    int sum=0; 
        for(int j =0; j<n; j++)
        {
            sum += matrix[j][i];
        }
    return sum;
}
