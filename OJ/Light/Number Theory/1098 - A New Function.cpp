#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    long long n, m;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &m);
        uint64_t res = 0, c;
        for(uint64_t a = 2; a * a <= m; a++){
            c = m / a;
            res += (a + c) * (c - a + 1) / 2;
            res += a * (c - a);
        }
        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}

