#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // searching starts from here
    int _max = arr[0], _min = _max;
    for(int i = 1; i < n; i++){
        if(arr[i] > _max) _max = arr[i];
        if(arr[i] < _min) _min = arr[i];
    }
    cout << "Max element of the array is: " << _max << endl << "Min element of the array is: " << _min << endl;
    return 0;
}

