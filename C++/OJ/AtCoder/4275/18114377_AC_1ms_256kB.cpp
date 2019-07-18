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
    string str;
    int mi = INT_MAX;
    cin >> str;
    for(int i = 0; i < str.size() - 2; i++){
        int t = stoi(str.substr(i, 3));
        mi = min(mi, abs(t - 753));
    }
    cout << mi << endl;
    return 0;
}


