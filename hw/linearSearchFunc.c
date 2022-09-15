#include<stdio.h>
#include<stdlib.h>
int linearSearch(int*,int,int);
int main(){
	int n,item;
        printf("Enter number of arrays to be inserted: ");
        scanf("%d" , &n);
        int *arr = (int*)malloc(n*sizeof(int));
        printf("Enter elements of array: ");
        for(int i =0 ; i<n ; i++)
                scanf("%d",arr+i);
        printf("Enter item to be searched: ");
        scanf("%d" , &item);

	printf("%s", linearSearch(arr,n,item)?"False":"True");
	return 0;
}
int linearSearch(int *arr, int arr_len,int item){
	 for(int j =0 ; j<arr_len;j++){
                if(arr[j] == item)
                                return 0;

        }
	return -1;
}
