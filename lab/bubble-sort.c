#include<stdio.h>
void bubble(int*,int);
void printArray(int*,int);
int main(){
	int arr[] = {9, 8,7,6,4,3,2,1};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,arr_len);
	bubble(arr,arr_len);
	printArray(arr,arr_len);
	return 0;
}

void bubble(int * arr, int arr_len){
	int swapped = 0; 
	for(int i = 0; i<arr_len ; i++){
		for(int j =1 ; j<arr_len - i ; j++){
			if(arr[j] < arr[j-1]){
				 int temp = arr[j];
				 arr[j] = arr[j-1];
				 arr[j-1] = temp;
				 swapped = 1;
			}
		}

	}

}

void printArray(int *arr,int len){
	for(int i =0 ; i<len;i++)
		printf("%d  " , arr[i]);
	printf("\n");
}
