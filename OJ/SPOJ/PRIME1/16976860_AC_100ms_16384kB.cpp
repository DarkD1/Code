#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> pp(10e6+1, true);
void sieve(){
    pp[0] = pp[1] = false;
    for(int i = 2; i * i <= 10e6; i++){
        if(pp[i]) for(int j = i * 2; j <= 10e6; j+= i) pp[j] = false;
    }
    for(int i = 0; i <= pp.size(); i++) if(pp[i]) prime.push_back(i);
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        uint64_t m, n;
        bool arr[100005];
        scanf("%lld %lld", &m, &n);
        if(m == 1) m++;
        uint64_t sqrtn = sqrtl(n);
        memset(arr, false, sizeof(arr));
        for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++){
            int p = prime[i]; uint64_t j = p * p;
            if(j < m) j = ((m + p - 1) / p) * p;
            for(; j <= n; j += p) arr[j-m] = true;
        }
        for(int i = m; i <= n; i++) if(arr[i-m] == false) cout << i << endl;
        cout << endl;
    }
    return 0;
}
