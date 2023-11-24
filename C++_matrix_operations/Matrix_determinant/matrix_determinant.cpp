#include<bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 4

// Determinant of matrix function
int Matrix_determinant(int mat[N][N], int n)
{
  int num1, num2, det = 1, index, total = 1; // Initialize result

  // temporary array for storing row
  int temp[n + 1];

  // loop through to traverse diagonal elements
  for(int i=0; i < n; i++) {
    index = i; // initialize the index

    // find which index has nonzero value
    while(index < n && mat[index][i] == 0) {
      index++;
    }

    // if there is nonzero element
    if(index == n) {
      continue; // the determinant of matrix is zero
    }

    if(index != i) {
      // loop for swapping diagonal element row and index row
      for(int j=0; j < n; j++) {
        swap(mat[index][j], mat[i][j]);
      }
      /* determinant sign changes when we shift rows
         go through determinant properties */
      det = det * pow(-1, index - i);
    }

    // storing the values of diagonal row elements
    for(int j=0; j < n; j++) {
      temp[j] = mat[i][j];
    }

    // traversing every row below the diagonal element
    for(int j=i+1; j < n; j++) {
      num1 = temp[i]; // value of diagonal element
      num2 = mat[j][i]; // value of next row element

      /* traversing every column of row and 
         multiplying to every row */
      for(int k=0; k < n; k++) {
        /* multiplying to make the diagonal
           element and next row element equal */
        mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);
      }

      total = total * num1; // Det(kA) = kDet(A)
    }
  }

  // multiplying the diagonal elements to get determinant
  for(int i=0; i < n; i++) {
    det = det * mat[i][i];
  }

  return (det / total); // Det(kA)/k=Det(A)

}

// Driver code
int main()
{
  /* int mat[N][N] = {{6, 1, 1},
                       {4, -2, 5},
                       {2, 8, 7}}; */

  int mat[N][N] = { { 1, 0, 2, -1 },
                    { 3, 0, 0, 5 },
                    { 2, 1, 4, -3 },
                    { 1, 0, 5, 0 } };

  // function call
  printf("Determinant of matrix is: %d\n",
         Matrix_determinant(mat, N));

  return 0;

}
