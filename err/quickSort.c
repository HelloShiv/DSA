#include<stdio.h>
void print(int *arr , int len){for(int i = 0 ; i < len ; i++)printf("%d ", arr[i]);printf("\n");}
void quickSort(int *,int ,int);
int main(){
	int arr[] = {12,9,8,7,6,5,4,3,21,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	print(arr,len);
	quickSort(arr,0,len-1);
	print(arr,len);
	return 0;
}

void quickSort(int *arr, int l , int hi){
	if(l>=hi) return;
	int s = l ;
	int e = hi ;
	int m = l + (hi-l)/2;
	int pivot = arr[m];
	while(s<=e){
		while(arr[s]<pivot)
			s++;
		while(arr[e]>pivot)
			e--;
		if(s<=e){
			int temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;
			e--;
		}
	}
	quickSort(arr,l,e);
	quickSort(arr,s,hi);

}
