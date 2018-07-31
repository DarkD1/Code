#include <bits/stdc++.h>
using namespace std;

int main(){
	map <string, int> m;
	int n;
	cin >> n;
	vector<string> x;
	while(n--){
		string a;
		cin >> a;
		x.push_back(a);
	}
	for(auto i: x){
		if(m[i] == 0){
			m[i]++;
			cout << "OK" << endl;
		}
		else {
			cout << i << m[i] << endl;
			m[i]++;
		}
	}
	return 0;
}

