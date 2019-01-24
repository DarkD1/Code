#include <bits/stdc++.h>
using namespace std;

namespace primes{
  const int MP = 100001;
  bool sieve[MP];
  long long primes[MP];
  int num_p;
  void fill_sieve() {
    num_p = 0;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i < MP; ++i) {
      if (!sieve[i]) {
        primes[num_p++] = i;
        for (long long j = i * i; j < MP; j += i)
          sieve[j] = true;
      }
    }
  }
  // Finds prime numbers between a and b, using basic primes up to sqrt(b)
  long long seg_sieve(long long a, long long b) {
    long long ant = a;
    a = max(a, 3LL);
    vector<bool> pmap(b - a + 1);
    long long sqrt_b = sqrt(b);
    for (int i = 0; i < num_p; ++i) {
      long long p = primes[i];
      if (p > sqrt_b) break;
      long long j = (a + p - 1) / p;
      for (long long v = (j == 1) ? p + p : j * p; v <= b; v += p) {
        pmap[v - a] = true;
      }
    }
    long long ans = 0;
    if (ant == 2) ans++;
    int start = a % 2 ? 0 : 1;
    for (int i = start, I = b - a + 1; i < I; i += 2)
      if (pmap[i] == false)
        ans++;
    return ans;
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    primes::fill_sieve();
    int n, l, r;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        if (l == 1 && r == 1) printf("Case %d: 0\n", i);
        else{
            int res = (int)primes::seg_sieve(l + (l == 1), r);
            printf("Case %d: %d\n", i, res);
        }
    }
    return 0;
}

