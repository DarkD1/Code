#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int x, y, m, n;
    cin >> m >> n >> x >> y;
    vector<int> a(m), b(n);
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = x + 1; i <= y; i++){
        int ca = 0, z = i, cb = 0;
        for(int v: a) if(v < z) ca++;
        if(ca != a.size()) continue;
        for(int v: b) if(v >= z) cb++;
        if(cb == b.size()) return cout << "No War", 0;
    }
    cout << "War";
    return 0;
}


