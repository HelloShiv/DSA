#include<stdio.h>
#include<stdlib.h>

int top = -1;

void insert(int* arr,int data){
	if(top == -1){
		arr[0] = data;
		top = 0;
	}
	else{
		top++;
		arr[top] = data;
	}
}

void print(int *arr ,int size){
	if(top == -1)
		return;
	int temp = top;
	for(int i = temp ; i > 0; i--)
		printf("%d ", arr[i]);
	
}

void pop(int *arr){
	if(top == -1)
		return ;
	printf("\n\n%d :POPED \n",arr[top] );
//	int del = top;
	top--;
//	free(arr[del]);
}

int main(){
	int n;
	printf("Enter number of element to be entered: ");
	scanf(" %d",&n );
	int *arr = (int*)calloc(n,sizeof(int));
	for(int i = 0 ; i < n ; i++)
		insert(arr,i);
	print(arr,n);
	pop(arr);pop(arr);
	print(arr,n);
	return 0;
}
