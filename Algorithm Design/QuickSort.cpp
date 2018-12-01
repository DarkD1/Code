#include <iostream>

using namespace std;
// swapping two values of an array
void swapp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// getting partition index of the array
int part(int *arr, int low, int high){
    int pivot = arr[high];
    int pidx = low;
    for(int i = low; i <= high; i++){
        if(pivot > arr[i]){
            swapp(&arr[i], &arr[pidx]);
            pidx++;
        }
    }
    swapp(&arr[pidx], &arr[high]);
    return pidx;
}
// quicksort
void quicksort(int *arr, int low, int high){
    if(low < high){
        int pIndex = part(arr, low, high);
        quicksort(arr, low, pIndex - 1);
        quicksort(arr, pIndex + 1, high);
    }
}

int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // quicksort starts from here
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}


