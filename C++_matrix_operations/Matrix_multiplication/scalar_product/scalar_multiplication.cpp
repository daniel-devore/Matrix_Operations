#include<bits/stdc++.h>
using namespace std;

#define N 3

// Define scalar multiple function
void scal_mult(int A[N][N], int k, int B[N][N])
{

  for(int i=0; i < N; i++)
    for(int j=0; j < N; j++)
      B[i][j] = k * A[i][j];

}

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
    {1,2,3},
    {4,5,6},
    {7,8,9},
  };

  display(matrixA);

  int matrixB[N][N];

  cout << "\nThe Scalar Product of the Matrix is:\n";
  scal_mult(matrixA, 2, matrixB);
  display(matrixB);
  


  return 0;

}
