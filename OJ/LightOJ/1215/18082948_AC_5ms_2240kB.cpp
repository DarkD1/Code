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

    uint64_t a, b, l, t, lcm;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> l;
        lcm = (a / __gcd(a, b)) * b;
        cout << "Case " << i << ": ";
        if(l % lcm){
            cout << "impossible" << endl;
        }
        else{
            uint64_t x = l / lcm, y;
            while((y = __gcd(x, lcm)) != 1){
                x *= y;
                lcm /= y;
            }
            cout << x << endl;
        }
//        dbg(lcm);

    }
    return 0;
}

