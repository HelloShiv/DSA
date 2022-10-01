#include "bubble-sort.h"
#include "insertion.h"
#include "merge.h"
#include "quicksort.h"
#include "selection.h"
int arr[] = {34,56,3,66,77,88};
int main(){
	int i ;
	scanf("%d" ,&i);
	int len = sizeof(arr)/sizeof(arr[0]);
	print(arr,len);
	switch(i){
	case 1: printf("Bubble Sort \n");
		BubbleSort(arr,len);
		break;
		
	case 2:printf("Insertion Sort\n");
		insertionSort(arr,len);
		break;
	case 3:printf("Merge Sort\n");
		mergeSort(arr,len);
		break;
	case 4:printf("Quick Sort \n");
		quickSort(0,len-1);
		break;

	case 5:printf("Insertion Sort\n");
		sort(arr,len);
		break;
		
	default:
		break;

}
	print(arr,len);

	return 0;
}
