#include<bits/stdc++.h>
using namespace std;

#define N 3
#define M 4

// Define function for matrix multiplication
void matrix_mult(int A[N][N], int B[N][M], int AB[N][M])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      AB[i][j]=0;
      for(int k=0; k < N; k++) {
        AB[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  // Declaring and initiallizing matrix
  int matrixA[N][N]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
  };

  int matrixB[N][M]={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
  };

  // Print original matrix
  cout << "Input Matrix A:\n";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << matrixA[i][j] << "\t";
    }
    cout << endl;
  }

  cout << "\nInput Matrix B:\n";
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      cout << matrixB[i][j] << "\t";
    }
    cout << endl;
  }

  // Declaring the new matrix
  int matrixAB[N][M];

  cout << "\nThe Product of the Matrices is:\n";
  matrix_mult(matrixA, matrixB, matrixAB);

  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      cout << matrixAB[i][j] << "\t";
    }
    cout << endl;
  }

  return 0;

}
