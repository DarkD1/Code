#include <iostream>

using namespace std;
// binary search
int bs(int arr[], int low, int high, int item){
    if(low <= high){
        int mid = (low + high) * .5;
        if(arr[mid] == item) return mid;
        if(arr[mid] > item) return bs(arr, low, mid - 1, item);
        else return bs(arr, mid + 1, high, item);
    }
    else return -1;
}
int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n], item, index;
    for(int i = 0; i < n; i++) cin >> arr[i];
    // binary search starts from here.
    cout << "Enter an element you want to search: ";
    cin >> item;
    int low = 0, high = n - 1;
    index = bs(arr, low, high, item);
    if(index == -1) cout << item << " not found in array" << endl;
    else cout << item << " found in " << index << " number index" << endl;
    return 0;
}
