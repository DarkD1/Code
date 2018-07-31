#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void bubble(int arr[], int n){
	int i, j;
	for(i = 0; i< n-1; i++)	for(j = 0 ; j< n-i-1; j++)	if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
}

int main(){
	int arr[] = {9,3,5,6,8,1};
	bubble(arr, 6);
	int i;
	for(i = 0; i<6; i++) printf("%d\t", arr[i]);
}