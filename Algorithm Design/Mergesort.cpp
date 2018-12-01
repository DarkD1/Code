#include <iostream>
#include <cstdlib>

using namespace std;
void _merge(int *left, int *right, int *a, int nL, int nR){
    int k = 0, i = 0, j = 0;
    while(i < nL && j < nR) (left[i] <= right[j])?  a[k++] = left[i++] : a[k++] = right[j++];
    while(i < nL) a[k++] = left[i++];
    while(j < nR) a[k++] = right[j++];
}
void mergesort(int *a, int n){
    if(n < 2) return;
    int mid = n / 2;
    int left[mid], right[n-mid];
    for(int i = 0; i < mid; i++) left[i] = a[i];
    for(int i = mid; i < n; i++) right[i-mid] = a[i];
    mergesort(left, sizeof(left) / sizeof(int));
    mergesort(right, sizeof(right) / sizeof(int));
    _merge(left, right, a, sizeof(left) / sizeof(int), sizeof(right) / sizeof(int));
}
int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergesort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

