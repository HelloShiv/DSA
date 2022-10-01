#include<stdio.h>
void BubbleSort(int *arr,int arrc){
	for(int i = 0 ; i<arrc; i++){
		for(int j = 1 ; j<arrc - i ;j++){
			if(arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}

}

