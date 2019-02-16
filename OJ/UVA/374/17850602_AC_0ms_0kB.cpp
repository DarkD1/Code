#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    long long a, b, c;
    while(scanf("%lld%lld%lld", &a, &b, &c) == 3){
        long long res = 1, x = a;
        while(b){
            if(b & 1){
                res = (res * x) % c;
            }
            x = (x * x) % c;
            b >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}
