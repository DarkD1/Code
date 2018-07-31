#include <stdio.h>

void insertionsort(int arr[], int n){
	int i, j, temp;
	for(i = 1 ; i< n; i++){
		temp = arr[i];
		for(j = i-1; j>=0; j--){
			if(temp < arr[j]) arr[j+1] = arr[j];
			else break;
		}
		arr[j+1] = temp;
	}
}

int main(){
	int arr[] = {9,3,5,6,-8,1};
	insertionsort(arr, 6);
	int i;
	for(i = 0; i<6; i++) printf("%d ", arr[i]);
}