#include<bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 4

/* First need to find the cofactor matrix,
   Build function to get cofactor matrix of 
   A[p][q] in temp[][].
   n is current dimension of A[][] */
void Cofactor_matrix(int A[N][N], int temp[N][N], int p, int q, int n)
{
  int i=0, j=0;

  // Loop through each element of matrix
  for(int row=0; row < n; row++) {
    for(int col=0; col < n; col++) {
      /* Copy elements not in given row and column 
         into temp matrix */
      if(row != p && col != q) {
        temp[i][j++] = A[row][col];

        /* row is filled, so increase row index 
           and reset col index */
        if(j == n - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

/* Recursive function for finding determinant of matrix
   n is current dimension of A[][] */
int matrix_determinant(int A[N][N], int n)
{
  int D=0; // intialize result

  // Base case: if matrix contains single element
  if(n == 1) {
    return A[0][0];
  }

  int temp[N][N]; // store cofactors
  int sign = 1; // store sign multiplier

  // Iterate for each element of first row
  for(int f=0; f < n; f++) {
    Cofactor_matrix(A, temp, 0, f, n);
    D += sign * A[0][f] * matrix_determinant(temp, n - 1);

    // terms alternate sign
    sign = -sign;
  }

  return D;

}

// Function to get adjoint(transpose) of A[N][N] in adj[N][N]
void adjoint(int A[N][N], int adj[N][N])
{
  if(N == 1) {
    adj[0][0] = 1;
    return;
  }

  // temp is used to store cofactors of A[][]
  int sign=1, temp[N][N];

  for(int i=0; i < N; i++) {
    for(int j=0; j < N; j++) {
      // Get cofactor matrix
      Cofactor_matrix(A, temp, i, j, N);

      /* sign of adj[j][i] positive if sum of row
         and column indices is even */
      sign = ((i + j) % 2 == 0) ? 1 : -1;

      /* Interchanging rows and columns to get 
         the transpose of cofactor matrix */
      adj[j][i] = (sign) * (matrix_determinant(temp, N - 1));
    }
  }

}

/* Function to calculate and store inverse, returns false
   if matrix is singular (Det = 0) */
bool matrix_inverse(int A[N][N], float inverse[N][N])
{
  // Find determinant of A[][]
  int det = matrix_determinant(A, N);
  if(det == 0) {
    cout << "Singular Matrix, No inverse";
    return false;
  }

  // Find adjoint
  int adj[N][N];
  adjoint(A, adj);

  // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
  for(int i=0; i < N; i++) {
    for(int j=0; j < N; j++) {
      inverse[i][j] = adj[i][j] / float(det);
    }
  }

  return true;

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

// Driver program
int main()
{
  int A[N][N] = { { 5, -2, 2, 7 },
                  { 1, 0, 0, 3 },
                  { -3, 1, 5, 0 },
                  { 3, -1, -9, 4} };

  int adj[N][N]; // store adjoint of A[][]
  float inv[N][N]; // store inverse of A[][]

  cout << "Input matrix is:\n";
  display(A);

  cout << "\nAdjoint Matrix is:\n";
  adjoint(A, adj);
  display(adj);

  cout << "\nThe Inverse Matrix is:\n";
  if(matrix_inverse(A, inv)) {
    display(inv);
  }

  return 0;

}
