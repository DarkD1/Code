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

int binarysearch(int arr[], int item, int n){
	int beg = 0, end = n-1, mid = ( beg + end )/2;
	while(beg < end){
		if (item == arr[mid]) {
			return 1;
		}
		if(item > arr[mid]) beg = mid + 1;
		else end = mid - 1;
		mid = ( beg + end )/2;
	}
	return 0;
}
int main(){
	int arr[] = {9,3,5,6,8,1};
	bubble(arr, 6);
	int res = binarysearch(arr, 1, 6);
	res == 1? printf("Item Found !!\n") : printf("Item Not Found !!\n");
	return 0;
}