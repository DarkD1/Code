#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    uint64_t n, t;
    while(cin >> n){
        if(n == 0) break;
        uint32_t res = 0;
        vector<int> factor;
        t = (int)sqrt(n);
        for(int i = 1; i <= t; i++){
            if(n % i == 0){
                factor.push_back(i);
                factor.push_back(n/i);
            }
        }
        if(t * t == n) factor.pop_back();
        for(int i = 0; i < factor.size(); i++){
            for(int j = i; j < factor.size(); j++){
                if(lcm(factor[i], factor[j]) == n) res++;
            }
        }
        cout << n << " " << res << endl;
    }
    return 0;
}
