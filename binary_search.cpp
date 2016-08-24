// This is the Binary Search as described in:
// The Algorithm Design Manual by Stevenn Skiena
// State: Complete

#include <cstdio>
bool binarySearch(int key, int *array, int low, int high) {
  if (low > high)
    return false;
  int midpoint = (low + high) / 2;
  if (array[midpoint] == key)
    return true;
  else if (array[midpoint] > key)
    return binarySearch(key, array, low, midpoint - 1);
  else if (array[midpoint] < key)
    return binarySearch(key, array, midpoint + 1, high);
  return false;
}

int main(int argc, char** argv) {
  int arr[10] = {1,2,3,4,5, 6,7,8,8,9};
  if (binarySearch(5, arr, 0, 10))
    printf("Found\n");
}
