#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n;
    bool found = false;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[n - 1] << " ";
    for(int i = n - 2; i >= 0; i--){
        if(v[n - 1] % v[i] != 0 || v[i + 1] == v[i]) {
            cout << v[i] << endl;
            return 0;
        }
    }
    return 0;
}