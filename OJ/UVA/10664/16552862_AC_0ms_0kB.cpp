#include<bits/stdc++.h>
using namespace std;

void solve(int n[], int k){
	int sum = accumulate(n, n+k, 0);
	if(sum % 2) {
		cout << "NO" << endl;
		return;
	}
	vector<bitset<41> > dp (sum+1);
	dp[0][0] = 1;
	for(int i = 0; i < k; i++)	for(int j = dp.size() - 1; j >= n[i]; j--) dp[j] |= dp[j-n[i]] << 1;
	if(dp[sum/2][k/2]) cout << "YES" << endl;
	else cout << "NO" << endl;
}


int main(){
	int n;
	cin >> n;
	string s;
	cin.ignore();
	while(n--){
        getline(cin,s);
        stringstream b(s);
        int k =0, a, arr[25];
        while(b>>a){
            arr[k] = a;
            k++;
        }
        solve(arr, k);
	}
	return 0;
}
