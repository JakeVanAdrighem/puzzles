/* PROBLEM: Find the median of two sorted arrays. */
/* Example: [1,2,3,5,6] [1,2]  Median = 2         */
// State: Incomplete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void getMedianValues(int *array, int size, int* set, int *setsize){
  if (size == 0) {
    return;
  } else if (size == 2) {
    set[*setsize] = array[0];
    set[*setsize + 1] = array[1];
    *setsize += 2;
  } else if (size % 2 == 0) {
    set[*setsize] = array[size / 2];
    set[*setsize + 1] = array[(size / 2) - 1];
    *setsize += 2;
  } else {
    set[*setsize] = array[size / 2];
    *setsize += 1;
  }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int *set = malloc(sizeof(int) * 4);
  int size = 0;

  getMedianValues(nums1, nums1Size, set, &size);
  getMedianValues(nums2, nums2Size, set, &size);

  printf("Size: %i\n", size);

  if (size == 0)
    return 0.0;
  if (size == 1)
    return set[0];
  else if (size == 2)
    return (double)(set[0] + set[1]) / 2;
  else {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
      if (set[i] > set[i + 1]) {
        printf("Swapping %i:%i and %i:%i\n", i, set[i], i + 1, set[i + 1]);
        tmp = set[i];
        set[i] = set[i + 1];
        set[i + 1] = tmp;
      }
    }
    if (size == 3)
      return set[1];
    else if (size == 4)
      return (double)(set[1] + set[2]) / 2;
  }
  return 0.0;
}

int main() {
  int size1 = 2;
  int array1[2] = {1, 2};
  int size2 = 2;
  int array2[2] = {1, 2};
  double res =
      findMedianSortedArrays((int *)&array1, size1, (int *)&array2, size2);
  printf("Median: %f\n", res);
  return 0;
}
