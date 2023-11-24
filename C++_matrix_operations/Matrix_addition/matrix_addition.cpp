#include<bits/stdc++.h>
using namespace std;

// Dimension of input matrices
#define N 4
#define M 3

// Define the matrix addition function
void matrix_addition(int matA[N][M], int matB[N][M], int matAB[N][M])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      matAB[i][j] = matA[i][j] + matB[i][j];
    }
  }
}

/* Generic function to display matrix. We use it to display both 
   the adjoint and inverse. adjoint is integer matrix and 
   inverse is float */
template <class T> void display(T matA[N][M])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      cout << matA[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // Declaring and initiallizing matrix
  int matrixA[N][M]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };

  int matrixB[N][M]={
    {11,12,13},
    {14,15,16},
    {17,18,19},
    {20,21,22}
  };

  // Declaring the new matrix
  int matrixAB[N][M];

  cout << "Input Matrix A is:\n";
  display(matrixA);

  cout << "\nInput Matrix B is:\n";
  display(matrixB);

  matrix_addition(matrixA, matrixB, matrixAB);

  cout << "\nSum of the matrices is:\n";
  display(matrixAB);

  return 0;

}
