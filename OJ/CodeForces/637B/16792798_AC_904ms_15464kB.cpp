#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
int main(){
	int n;
	cin >> n;
    vector<string> v(n);
    cin.ignore();
    unordered_map <string , int> mp;
    for(int i = n-1; i >=0 ; i--){
		cin >> v[i];
		mp[v[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(mp[v[i]] == 0) continue;
        if(mp[v[i]] >= 1){
            cout << v[i]<< endl;
            mp[v[i]] = 0;
        }
    }
	return 0;
}



