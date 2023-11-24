#include<bits/stdc++.h>
using namespace std;

#define N 4
#define M 3

void transpose_matrix(int A[N][M], int B[M][N])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      B[j][i] = A[i][j];
    }
  }
}

template <class T> void display_rect(T A[N][M])
{
  for(int i=0; i < N; i++) {
    for(int j=0; j < M; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

template <class T> void display_rect2(T A[M][N])
{
  for(int i=0; i < M; i++) {
    for(int j=0; j < N; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  // Declaring and initiallizing matrix
  int matrix[N][M]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };

  // Print original matrix
  cout << "Showing Original Matrix\n";
  display_rect(matrix);

  /* Declaring transposed matrix
    of dimmensions MxN */
  int transposed_matrix[M][N];

  transpose_matrix(matrix, transposed_matrix);

  // Print transposed matrix
  cout << "\nShowing Transposed Matrix\n";
  display_rect2(transposed_matrix);

  return 0;

}
