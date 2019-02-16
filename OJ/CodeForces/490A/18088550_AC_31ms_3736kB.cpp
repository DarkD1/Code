#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    vector<int> v[4];
    int n, x, m = 5005;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= 3; i++) m = min((int)v[i].size(), m);
    cout << m << endl;
    for(int i = 0; i < m; i++){
        cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << endl;
    }
    return 0;
}