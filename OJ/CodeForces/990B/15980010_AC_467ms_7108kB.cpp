#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,c=0;
    map<int, int> m;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < n-1; i++)    if(a[i] < a[i+1] && a[i] + k >= a[i+1]) c += m[a[i]];
    cout << n - c;
    return 0;
}
