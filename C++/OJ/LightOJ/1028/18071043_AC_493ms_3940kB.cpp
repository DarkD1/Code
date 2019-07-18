#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

const int N_SIZE = 1000007;
vector<int64_t> primes;

void get_primes(){
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    get_primes();
    int64_t n, t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        if(n == 1){
            cout << "Case " << i << ": " << 0 << endl;
            continue;
        }
        int64_t cnt = 1, pf = primes[0], k = 0;
        while(pf * pf <= n){
            int pwr = 0;
            while(n % pf == 0){
                n /= pf;
                pwr++;
            }
            cnt *= (pwr + 1);
            pf = primes[++k];
        }
        if(n != 1) cnt *= 2;
        cout << "Case " << i << ": " << cnt - 1 << endl;
    }
    return 0;
}

