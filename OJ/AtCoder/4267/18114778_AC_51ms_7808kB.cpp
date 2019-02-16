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
    vector<int> x(100005), y(100005), z[100005];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        z[x[i]].push_back(y[i]);
    }
    for(int i = 1; i <= n; i++)
        sort(z[i].begin(), z[i].end());
    for(int i = 0; i < m; i++){
        long long s = (long long) x[i] * 1000000;
        s += lower_bound(z[x[i]].begin(), z[x[i]].end(), y[i]) - z[x[i]].begin() + 1;
        printf("%012lld\n", s);
    }
    return 0;
}
