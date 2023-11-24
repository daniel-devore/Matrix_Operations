#include<bits/stdc++.h>
using namespace std;

#define N 2

// Define dot product function
int dot_prod(int A[N][N], int B[N][N])
{
  int scal=0; // Initialize scalar for dot product

  for(int i=0; i < N; i++) {
    for(int j=0; j < N; j++) {
      scal += A[i][j] * B[i][j];
    }
  }

  return scal;

}

// Generic function to print matrices
template <class T> void display(T A[N][N])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < N; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {

  // Declaring and initiallizing matrix
  int matrixA[N][N]={
    {1,2},
    {3,4},
  };

  int matrixB[N][N]={
    {1,1},
    {2,2},
  };

  // Print original matrix
  cout << "Input Matrix A:\n";
  display(matrixA);

  cout << "\nInput Matrix B:\n";
  display(matrixB);

  cout << "\nThe Dot Product of the Matrices is: ";
  cout << dot_prod(matrixA, matrixB) << endl;

  return 0;

}
