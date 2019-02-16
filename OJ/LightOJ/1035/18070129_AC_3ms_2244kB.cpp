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

    int n, t;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        vector<int> v;
        map<int, int> res;
        for(int i = 2; i <= n; i++) v.push_back(i);
        for(int i = 0; i < primes.size() && primes[i] <= n; i++){
            for(int j = 0; j < v.size(); j++){
                if(v[j] == 1 || v[j] % primes[i] != 0) continue;
                int cnt = 0;
                while(v[j] % primes[i] == 0){
                    v[j] /= primes[i];
                    cnt++;
                }
                res[primes[i]] += cnt;
            }
        }
        cout << "Case " << i << ": " << n << " = " ;
        int l = res.size(), c = 0;
        for(auto i: res){
            cout << i.first << " (" << i.second << ")";
            if(++c < l) cout << " * ";
        }
        cout << endl;
    }
    return 0;
}
