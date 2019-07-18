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
    int64_t n, sum = 0, maxv = -1, v;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v;
        sum += v;
        maxv = max(maxv, v);
    }
    sum -= (maxv / 2);
    cout << sum << endl;
    return 0;
}

