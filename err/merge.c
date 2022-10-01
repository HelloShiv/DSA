#include<stdio.h>
#include<cstring>
#include<stdlib.h>
void print(int * arr,int arr_len){for(int i =0 ; i <arr_len;i++)printf("%d  ", arr[i]);printf("\n");}
void mergeSort(int* arr,int start, int end);
 void merge(int*,int *left,int left_size,int *right,int right_size);
int main(){
	int arr[] = {56,43,119,8,7,6,5,3,2,1};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	print(arr,arr_len);
	mergeSort(arr,0,arr_len);
	print(arr,arr_len);
	return 0;
}

void mergeSort(int* arr,int start, int end){
	if(end>1){
		int mid = (end - start)/2;
		int *left = (int*)calloc(mid,sizeof(int));
		int *right = (int*)calloc((end-mid),sizeof(int));
		memcpy(left,arr,mid*sizeof(int));
//		print(left,mid);
		for(int j =0 ; j < end -mid ; j++)
			right[j] = arr[mid+j];
//		memcpy(right,&arr[end-mid],(end-mid)*sizeof(int));
	//	print(right,mid+1);
		mergeSort(left,0,mid);
		mergeSort(right,0,end-mid);
		merge(arr,left,mid,right,end-mid);		
 
	}
}

void merge(int *arr,int *left,int left_size,int *right,int right_size){
	;
	int i, j, k;
        int n1 = left_size;
        int n2 = right_size;
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

   
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
	
}
