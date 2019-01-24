#include <bits/stdc++.h>
using namespace std;
#define maxL (1000000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
int mark[maxL];
int p[700000], pt = 0;
void sieve() {
    register int i, j, k;
    SET(1);
    int n = 1000000;
    for(i = 2; i <= n; i++) {
        if(!GET(i)) {
            p[pt++] = i;
            for(k = n/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
        }
    }
}
int isprime(int n) {
    if(n < 1000000)
        return !GET(n);
    static int sq, i;
    sq = (int)sqrt(n);
    for(i = 0; i < pt && p[i] <= sq; i++)
        if(n%p[i] == 0)
            return 0;
    return 1;
}
int get_powers(long int n, int p) {
    int res = 0;
    for (unsigned long int power = p; power <= n; power *= p) {
        res += n / power;
    }
    return res;
}
bool res(int n, int m){
    if(m == 0) return false;
    if(n >= m) return true;

    int cnt = 0, m2 = m;
    map<int, int> mp;
    vector<long long int> factor, factorial;
    for(int i = 2; i <= 50000 && m2; i++){
        if(isprime(i)){
            while(m2 % i == 0){
                m2 /= i;
                factor.push_back(i);
                mp[i]++;
            }
        }
    }
    if(m2 > 1)   factor.push_back(m2), mp[m2]++;
    for(int i = 0; i < factor.size(); i++){
        if(mp[factor[i]] - get_powers(n, factor[i]) > 0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    sieve();

    long long int n, m;
    while(scanf("%lld%lld", &n, &m) == 2){
        if(res(n, m)) printf("%lld divides %lld!\n", m, n);
        else printf("%lld does not divide %lld!\n", m, n);
    }
    return 0;
}
