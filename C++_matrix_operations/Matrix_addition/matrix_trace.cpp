#include<bits/stdc++.h>
using namespace std;

#define N 3

/* Define function to find the trace
   of the matrix */
int Trace_mat(int A[N][N])
{
  // Initialize result
  int T=0;

  for(int i=0; i < N; i++)
    T += A[i][i];

  return T;
}

/* Generic function to display matrix. We use it to display both 
   the adjoint and inverse. adjoint is integer matrix and 
   inverse is float */
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
  int matrix[N][N] = { {1,2,3},
                       {4,5,6},
                       {7,8,9} };

  
  // Print original matrix
  cout << "Input Matrix:\n";
  display(matrix);

  cout << "\nThe Trace Of The Matrix Is: ";
  cout << Trace_mat(matrix) << endl;

  return 0;

}
