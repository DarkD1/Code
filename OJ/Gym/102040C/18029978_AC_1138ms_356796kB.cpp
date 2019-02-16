#include<bits/stdc++.h>
#define YOU using
#define ARE namespace
#define LUCKY std

YOU ARE LUCKY;

const int MOD = 1e7 + 7;
const int N_MAX = 1e6;
const int PRIMES_SIZE = 78498;
int cur[N_MAX + 1], to_index[N_MAX + 1], t, f[1000][PRIMES_SIZE];
vector<int> primes, prime_factors[N_MAX + 1];
pair<int, int> n[1000];
long long ans[1000];

int main(){
    // Initializing to cur 2 to Max N
    for(int i = 2; i <= N_MAX; i++)
        cur[i] = i;
    // Prime Factors and Prime Numbers upto N_MAX
    for(int i = 2; i <= N_MAX; i++){
        if(cur[i] != i){
            continue;
        }
        primes.push_back(i);
        for(int j = i; j <= N_MAX; j += i){
            while(cur[j] % i == 0){
                prime_factors[j].push_back(i);
                cur[j] /= i;
            }
        }
    }
    // nth prime number
    for(int i = 0; i < PRIMES_SIZE; i++){
        to_index[primes[i]] = i;
    }
    t = 0;
    while(true){
        int x;
        cin >> x;
        if(x == 0) break;
        n[t].first = x;
        n[t].second = t;
        t++;
    }
    sort(n, n + t);
    for(int i = 0; i < t; i++){
        for(int j = 0; j < PRIMES_SIZE; j++){
            f[i][j] = 0;
        }
    }

    for(int i = 0, j = 1; i < t; i++){
        if(i > 0){
            for(int k = 0; k < PRIMES_SIZE; k++){
                f[i][k] = f[i- 1][k];
            }
        }
        while(j <= n[i].first){
            for(auto prime_factor: prime_factors[j]){
                f[i][to_index[prime_factor]]++;
            }
            j++;
        }
    }
    for(int i = 0; i < t; i++){
        ans[n[i].second] = 1;
        for(int j = 0; j < PRIMES_SIZE; j++){
            if(f[i][j] == 0){
                continue;
            }
            long long x = ((long long)(f[i][j] + 1) * (f[i][j] + 2)) / 2;
            ans[n[i].second]= (ans[n[i].second] * x) % MOD;
        }
    }
    for(int i = 0; i < t; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
