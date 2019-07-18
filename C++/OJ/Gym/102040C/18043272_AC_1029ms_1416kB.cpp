#include<bits/stdc++.h>
#define THE using
#define DARK namespace
#define ONE std

THE DARK ONE;

const int N_SIZE = 1000007;
const int MOD = 10000007;
vector<int> get_primes(){
    vector<int> primes;
    char *sieve;
    sieve = new char[N_SIZE/8+1];
    memset(sieve, 0xFF, (N_SIZE/8+1) * sizeof(char));
    for(int x = 2; x <= N_SIZE; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            for(int j = 2*x; j <= N_SIZE; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return primes;
}
int main(){
    vector<int> primes = get_primes();
    int n;
    while(cin >> n){
        if(n == 0) break;
        long long res = 1;
        for(int p: primes){
            if(p > n) break;
            int v = n, a = 1;
            while(v){
                v /= p;
                a += v;
            }
            res = (res * ((1LL * a * (a + 1) / 2 % MOD))) % MOD;
        }
        cout << res << endl;
    }
    return 0;
}

