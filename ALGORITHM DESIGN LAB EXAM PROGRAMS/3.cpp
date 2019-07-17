#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// getting partition index of the array
int part(int *arr, int low, int high){
    int pivot = arr[high];
    int pidx = low;
    for(int i = low; i <= high; i++){
        if(pivot > arr[i]){
            swap(arr[i], arr[pidx]);
            pidx++;
        }
    }
    swap(arr[pidx], arr[high]);
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
void bubble(int *arr, int n){
    for(int i = 0; i < n - 1; i++) for(int j = 0 ; j < n - i - 1; j++)  if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}
int main(){
    int n;
    cin >> n;
    int arr[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    clock_t start, end, diff;
    double t;
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    diff = end - start;
    t = (diff * 1.0 / CLOCKS_PER_SEC) / 1000;
    cout << "Quick Sort Takes : " << t << " ms" << endl;

    start = clock();
    bubble(arr2, n);
    end = clock();
    diff = end - start;
    t = (diff * 1.0 / CLOCKS_PER_SEC) / 1000;
    cout << "Bubble Sort Takes : " << t << " ms" << endl;

    return 0;
}
