#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
int main(){
	ll n, cost = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) arr[i] = i+1;
	int f = 0, l = arr.size() - 1;
	for(int i = 0; i < n-1; i++){
		f = 0, l = arr.size() - 1;
        cost += (arr[f] + arr[l]) % (n+1);
        if(i & 1) arr.pop_back();
        else arr.erase(arr.begin());
	}
	cout << cost << endl;
	return 0;
}


