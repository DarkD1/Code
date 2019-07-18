#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high){
	int i = low-1, pivot = arr[high], j;
	for(j = low; j< high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	int k;
	for(k=0; k< 5; k++)	printf("%d ", arr[k]);
	printf("\n");
	return i+1;
}

void quick(int arr[], int low, int high){
	if(low < high){
	int i;
	for(i=0; i< 5; i++)	printf("%d ", arr[i]);
	printf("\n");
		int pi = partition(arr, low, high);
		quick(arr, low, pi-1);
		quick(arr, pi+1, high);
	}
}

int main(){
	int arr[] = {50,45,31,55,-5};
	quick(arr, 0, 4);
	int i;
	printf("\n\n\n");
	for(i=0; i< 5; i++)	printf("%d ", arr[i]);
	return 0;
}