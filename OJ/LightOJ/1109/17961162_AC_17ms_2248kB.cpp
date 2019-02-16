#include <bits/stdc++.h>
using namespace std;

int NOD(uint64_t n){
    uint64_t t = n;
    map<int, int> mp;
    int p = 2;
    while(p * p <= n){
        while(n % p == 0){
            n /= p;
            mp[p]++;
        }
        p += 1 + p % 2;
    }
    if(n > 1) mp[n]++;
    int res = 1;
    for(auto i: mp) res *= (i.second + 1);
    return res;
}
bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    vector<pair<int, int> > res(1001);
    for(int i = 1; i <= 1000; i++){
        res[i - 1] = make_pair(NOD(i), i);
    }
    sort(res.begin(), res.end(), comp);
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        cout << "Case " << i << ": " << res[m].second << endl;
    }
    return 0;
}

