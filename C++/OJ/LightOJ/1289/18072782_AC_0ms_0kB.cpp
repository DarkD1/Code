#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl
#define MOD 4294967296
THE DARK ONE;

const int N_SIZE = 100000000;
int cnt = 0;
//vector<unsigned> primes;
int primes[5761465];
unsigned int dp[5761465];

void get_primes(){
    char *sieve;
    sieve = new char[N_SIZE/8+1];
    memset(sieve, 0xFF, (N_SIZE/8+1) * sizeof(char));
    for(int x = 2; x <= 100000; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            for(int j = 2*x; j <= N_SIZE; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    primes[cnt++] = 2;
    dp[cnt - 1] = 2;
    for(int i = 3; i <= N_SIZE; i += 2){
        if(sieve[i/8] & (0x01 << (i % 8))){
            primes[cnt++] = i;
            dp[cnt - 1] = dp[cnt - 2] * i;
        }
    }
    delete[] sieve;
}
unsigned int find_product(int x){
	unsigned int ans;
	int64_t temp;
	int k = upper_bound(primes, primes + cnt, x) - primes - 1;
	ans = dp[k];
	for(int i = 0; i < k; i++ ) {
        temp = primes[i] * primes[i];
        if(temp > x) break;
		while(temp <= x) {
			temp = temp * (int64_t)primes[i];
			ans = (ans * primes[i]);
		}
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);

    get_primes();
    unsigned int ans;
    int n, t, k;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        ans = find_product(n);
        printf("Case %d: %u\n", i, ans);
    }
    return 0;
}


