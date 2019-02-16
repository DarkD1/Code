#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);
    int n, t, k, d, cakesMade = 0, timeOne = 0, timeTwo, g = 0;
    cin >> n >> t >> k >> d;
    g = (n + k - 1) / k;
    timeTwo = d;
    for(int i = 0; i < g; i++){
        if(timeOne <= timeTwo) timeOne += t;
        else timeTwo += t;
    }
    max(timeOne, timeTwo) < g * t ? cout << "YES" : cout << "NO";
    return 0;
}
