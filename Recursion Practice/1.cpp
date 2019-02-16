#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int i){
    if(i < 0) return;
//    cout << arr[i];
    printf("%d", arr[i]);
    if(i > 0){
        printf(" ");
    }
    print(arr, i - 1);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    print(arr, n - 1);
    return 0;
}
