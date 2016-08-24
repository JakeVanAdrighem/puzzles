// PROBLEM: Find the sqrt of a number n.
// State: Incomplete
#include <cstdio>

long long sqrt(long long val, long long low, long long high){
  if(low > high)
    return -1;
  long long midpoint = (low + high) / 2;
  if((midpoint * midpoint) > val){
    return sqrt(val, low, midpoint - 1);
  }
  else if((midpoint * midpoint) < val){
    return sqrt(val, midpoint + 1, high);
  }
  else if((midpoint * midpoint) == val)
    return midpoint;
  return -1;
}

int main(){
  long long test = 1024;
  printf("%lli\n", sqrt(test, 1, test));
}
