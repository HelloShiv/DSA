#include<stdio.h>
void swap(int *arr,int first,int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void print(int *arr,int arrc){
	for(int i=0;i<arrc;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void cycleSort(int *arr,int arrc){
	print(arr,arrc);
	for(int i=0;i<arrc;i++){
		int correct = arr[i] - 1 ;
		if( arr[correct] != arr[i]){
			swap(arr,i,correct);
		}
	}
	print(arr,arrc);
}


int main(){
	int arr[] = {1,2,9,8,4,3,7,5,6 };
	cycleSort(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
