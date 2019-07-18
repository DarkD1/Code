#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long k, x;
        cin >> k >> x;
        cout << 9LL * (k - 1) + x << endl;
    }
    return 0;
}
