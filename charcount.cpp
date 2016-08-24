/* PROBLEM: Compute the number of characters required to print all numbers from 1 to n. */
/* EXAMPLE: Input: 12 Output: 15                                                        */
/* Input: 23 Output: 37                                                                 */
#include <cstdio>

int compute(int n){
  if(n < 10)
    printf("%i\n", n);
  int numchars = 9;
  int numwidth = 2;
  int depth = 10;
  while(n > depth){
    numchars += ((n / depth) * depth - (depth - 1)) * numwidth;
    depth = depth * 10;
    numwidth++;
  }
  return numchars;
}

int main(){
  int res = compute(101);
  printf("%i\n", res);
  return 0;
}
