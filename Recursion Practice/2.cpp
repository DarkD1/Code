#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int low, int high){
    if(low > high) return;
    printf("%d - %d\n", arr[low], arr[high]);
    print(arr, low + 1, high - 1);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    print(arr, 0, n - 1);
    return 0;
}

