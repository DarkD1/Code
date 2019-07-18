#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;

int main(){
    int n;
    freopen ("input.txt","r",stdin);
    cin >> n;
    int x = n, y = n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    fclose (stdin);
    sort(v.begin(), v.end());
	int i = 0, bi, m = n;
	while(i < n){
        if(i >= m) break;
        bi = upper_bound(v.begin(), v.end(), v[i]* 2) - v.begin();
        m = min(m, i + n - bi);
        i++;
	}
    freopen ("output.txt","w",stdout);
    cout << m;
    fclose (stdout);
	return 0;
}

