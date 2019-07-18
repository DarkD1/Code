#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
bool nextprime(int n){
	for(int i = 2; i * i<= n; i++) if(n % i == 0) return false;
	return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    int nextP;
    for(int i = n +1; ; i++) {
		if(nextprime(i)){
            nextP = i;
            break;
		}
    }
    if(nextP == m) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}


