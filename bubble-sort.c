#include<stdio.h>
void sort(int *arr,int arrc){
	for(int i = 0 ; i<arrc; i++){
		for(int j = 1 ; j<arrc - i ;j++){
			if(arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}

	for(int l = 0 ; l<arrc ;l++){
		printf("%d " , arr[l]);
	}
}


int main(){
	int arr[] = {9,8,7,5,3,2,1,0};
	sort(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
