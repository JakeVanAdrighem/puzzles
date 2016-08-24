// PROBLEM: Given an integer n, print a progressively reducing pattern.
// EXAMPLE: 
// n = 4                    n = 6
// 4444                     666666
// 4334                     655556
// 4334                     654456
// 4444                     654456
//                          655556
//                          666666

#include <cstdio>

void printIt(int n, int width){
  for(int i = 0; i < width; i++)
    printf("%i", n);
}

int main(){
  printIt(4, 4);
  printf("\n");
}
