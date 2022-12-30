#include <stdio.h>
void sort(int *, int);
void swap(int *, int, int);
void print(int *, int);
void sort(int *arr, int arrc) {
  // i<n-2 j = i+1
  print(arr, arrc);
  printf("\n");
  for (int i = 0; i < arrc - 1; i++) {
    for (int j = i + 1; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr, j, j - 1);
      } else {
        break;
      }
    }
  }
  print(arr, arrc);
}

void swap(int *arr, int first, int last) {
  int temp = arr[first];
  arr[first] = arr[last];
  arr[last] = temp;
}
void print(int *arr, int arrc) {
  for (int i = 0; i < arrc; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {9, 8, 7, 64, 3, 2, 1, 4};
  sort(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}
