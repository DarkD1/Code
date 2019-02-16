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
    int n, c;
    cin >> n >> c;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for(auto i: v)
        if(i.second <= c)
            return cout << i.first, 0;
    cout << "TLE" << endl;
    return 0;
}
