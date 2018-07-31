#include <stdio.h>
void merge(int arr[], int i1, int j1, int i2, int j2);
void mergesort(int arr[], int i, int j){
	int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(arr, i, mid);
        mergesort(arr, mid+1, j);
        merge(arr, i, mid, mid+1, j);
    }
}
void merge(int arr[], int i1, int j1, int i2, int j2){
	int temp[50];
	int i = i1, j = i2, k = 0;
	while(i <= j1 && j<=j2)	temp[k++] = arr[i] < arr[j]? arr[i++]: arr[j++];
	while(i<=j1) temp[k++] = arr[i++];
	while(j<=j2) temp[k++] = arr[j++];

	for(i = i1 , j = 0; i<=j2; i++,j++) arr[i] = temp[j]; 
}
int main(){
	int arr[] = {9,3,5,6,-8,1};
	mergesort(arr, 0, 6-1);
	int i;
	for(i = 0; i<6; i++) printf("%d ", arr[i]);
}