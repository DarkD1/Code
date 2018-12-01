#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n], item, index = -1;
    for(int i = 0; i < n; i++) cin >> arr[i];
    // binary search starts from here.
    cout << "Enter an element you want to search: ";
    cin >> item;
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) * .5;
        if(arr[mid] == item){
            index = mid;
            break;
        }
        if(arr[mid] > item) high = mid - 1;
        else low = mid + 1;
    }
    if(index == -1) cout << item << " not found in array" << endl;
    else cout << item << " found in " << index << " number index" << endl;
    return 0;
}
