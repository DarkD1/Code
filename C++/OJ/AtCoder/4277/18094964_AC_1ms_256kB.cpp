#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;
map<int, int> factor(int n){
    map<int, int> f;
    int p = 2;
    while(p * p <= n){
        while(n % p == 0){
            n /= p;
            f[p]++;
        }
        p += 1 + p % 2;
    }
    if(n > 1) f[n]++;
    return f;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int n, ans = 0;
    cin >> n;
    map<int, int> p, cnt;
    for(int i = 2; i <= n; i++){
        map<int, int> tmp = factor(i);
        for(auto pi: tmp){
            p[pi.first] += pi.second;
        }
    }
    for(auto pi: p){
        if(pi.second >= 74) cnt[74]++;
        if(pi.second >= 24) cnt[24]++;
        if(pi.second >= 14) cnt[14]++;
        if(pi.second >= 4) cnt[4]++;
        if(pi.second >= 2) cnt[2]++;
    }
    ans += cnt[74];
    ans += cnt[24] * (cnt[2] - 1);
    ans += cnt[14] * (cnt[4] - 1);
    ans += (cnt[4] * (cnt[4] - 1)) / 2 * (cnt[2] - cnt[4]);
    ans += (cnt[4] * (cnt[4] - 1)) / 2 * (cnt[4] - 2);

    cout << ans << endl;
    return 0;
}

