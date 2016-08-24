// PROBLEM: Need to print the Kth element of a spiral form N x M matrix
// EXAMPLE:
// With k = 10
// [][][][][]
// [][][][][]
// [][][][][]
// [][][k][][]
// Status: Incomplete
#include <cstdio>
#include <cstdlib>

int findElement(int matrix[4][4], int n, int m, int k) {
  int pos = 0;
  // k not in the range of possible elements
  if((n * m) < k){
    printf("Out of range!\n");
    return -1;
  }
  if(k < m)
    printf("kth value in top row\n");
  if(k < (m + n - 1))
    printf("kth value in rightmost column\n");
  if(k < (m + n + m - 2))
    printf("kth value in bottom row\n");
  if(k < (m + n + m + n - 4))
    printf("kth value in leftmost column\n");
  else
    findElement(matrix[1][1], n - 1, m - 1, k - ((n + m) * 2));
}

int main(){
  int matrix[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int res = findElement(matrix, 4, 4, 12);
  printf("Result: %i\n", res);
}
