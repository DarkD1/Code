#include <bits/stdc++.h>
using namespace std;
void selectionSort(int *v, int n){
    for(int i = 0; i < n; i++){
        int m = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[m]){
                m = j;
            }
        }
        swap(v[i], v[m]);
    }
}
int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++) cin >> v[i];
    selectionSort(v, n);
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
