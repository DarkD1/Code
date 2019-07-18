#include<bits/stdc++.h>
using namespace std;
bool prime[10000000];
void sieve(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= 10000000; i++){
        if(prime[i]){
            for(int j = i*2; j <= 1000000; j+=i){
                prime[j]= false;
            }
        }
    }
}

int main(){
    sieve();
    int n;
    while(cin >> n){
        if(n == 0) break;
        bool f = false;
        for(int i = 2; i <= n; i++){
            if(prime[i] && prime[n-i]){
                cout << n << ":" << endl;
                cout << i << "+" << n-i << endl;
                f = true;
                break;
            }
        }
        if(!f) {
            cout << n << ":" << endl;
            cout << "NO WAY!" << endl;
        }
    }
    return 0;
}



