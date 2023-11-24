#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
  // Defining matrix dimensions
  int N=1, M=4;

  // Declaring and initiallizing matrix
  int vector[N][M]={
    {1,2,2,4}
  };

  // Print original matrix
  cout << "Showing Original Vector\n";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << vector[i][j] << "\t";
    }
    cout << endl;
  }

  /* Declaring New vector to 
     store for unit vector and 
     a variable for the magnitude*/
  double unit_vector[N][M];
  int square_sum=0;
  double mag;

  /* The matrix must be a column
     or a row vector */

  if (N == 1 || M == 1) {
    for(int i=0; i < N; i++) {
      for(int j=0; j < M; j++) {
        square_sum += vector[i][j] * vector[i][j];
      }
    }
    mag = sqrt(square_sum);

    cout << "\nThe unit vector is: \n";
    for(int i=0; i < N; i++) {
      for(int j=0; j < M; j++) {
        unit_vector[i][j] = vector[i][j] / mag;
        cout << unit_vector[i][j] << "\t";
      }
      cout << endl;
    }
  }

  return 0;

}
