#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int i, int j, int &n){
    if(i == n){
        n = j;
        return;
    }
    if(!(arr[i] & 1)) arr[j++] = arr[i];
    print(arr, i + 1, j, n);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    print(arr, 0, 0, n);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

