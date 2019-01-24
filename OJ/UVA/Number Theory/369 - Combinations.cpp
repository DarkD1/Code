#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n, m;
    while(cin >> n >> m){
        if(!n && !m) break;
        long long int res = 1;
        vector<int> N(n), D;
        iota(N.begin(), N.end(), 1);
        int c = max(n - m, m);
        int d = min(n - m, m);
        D = vector<int>(d);
        iota(D.begin(), D.end(), 1);
        for(int i = 1; i < c; i++) N[i] = 1;
        for(int i = 0; i < d; i++){
            for(int j = N.size() - 1; j >= 0; j--){
                if(N[j] % D[i] == 0 && D[i] != 1 && N[j] != 1){
                    N[j] /= D[i];
                    D[i] = 1;
                }
            }
        }
        for(int i: N)   res *= i;
        for(int i: D)   res /= i;
        cout << n << " things taken " << m << " at a time is " << res << " exactly."<< endl;
    }
    return 0;
}
