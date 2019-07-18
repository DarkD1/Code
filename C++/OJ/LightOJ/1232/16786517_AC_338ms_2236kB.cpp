#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        ull m, n;
        cin >> m >> n;
        vector<ull> v(m), p(n+1, 0);
        p[0] = 1;
        for(int j = 0; j < m; j++) cin >> v[j];
        for(ull k = 0; k < m; k++) {
            for(ull l = v[k]; l <= n; l++) p[l] = (p[l] % 100000007) + (p[l-v[k]] % 100000007);
        }
        ull ans = p[n] % 100000007;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
