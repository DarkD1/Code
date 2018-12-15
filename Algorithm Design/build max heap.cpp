#include <bits/stdc++.h>

using namespace std;

void heapify(int *arr, int n, int i){
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main(){
    int n;
    cout << "Array size: ";
    cin >> n;
    int arr[n];
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
