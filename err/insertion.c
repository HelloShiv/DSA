#include<stdio.h>
void print(int *arr,int len){for(int i =0 ; i < len ; i++)printf("%d ", arr[i]);printf("\n");}
void insertion(int * , int);
int main(){
	int arr[] = {5,4,3,7,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	print(arr,len);
	insertion(arr,len);
	print(arr,len);
	return 0;
}

void insertion(int *arr, int len){
	for(int i = 1 ; i < len ; i++){
		int key = arr[i];
		int j = i - 1 ;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j - 1;
		} 
		arr[j+1] = key;
	}
}
