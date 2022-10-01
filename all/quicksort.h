#include<stdio.h>
extern int arr[];
void quickSort(int p ,int q);
int  partition(int a[] , int m , int n);
void interchange(int a[],int i, int j);


void quickSort(int p ,int q){
	int j;
	if(p<q){
		j=partition(arr,p,q+1);
		quickSort(p,j-1);
		quickSort(j+1,q);
	}

}

int  partition(int a[] , int m , int n){
	int v = a[m] , i = m , j = n;
	do{
		do i = i+1;
			while(a[i]<v);
		do j = j-1;
			while(a[j]>v);
		if(i<j) interchange(a,i,j);
	}
	while(i<j);
	a[m] = a[j];
	a[j] = v;
	return j;

}
void interchange(int a[],int i, int j){
	int t= a[i];
	a[i] = a[j];
	a[j] = t;

}
