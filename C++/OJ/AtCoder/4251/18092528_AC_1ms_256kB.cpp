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
    vector<int> v(3);
    for(int i = 0; i < 3; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    cout << stoi(to_string(v[0]) + to_string(v[1])) + v[2] << endl;
    return 0;
}

