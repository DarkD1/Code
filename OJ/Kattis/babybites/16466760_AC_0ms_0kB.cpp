#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int main () {
    int n;
    string w, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> w;
    	if(w != "mumble"){
    		x = to_string(i);
    		if(x != w) {
    			cout << "something is fishy" << endl;
    			return 0;
    		}
    	}
    }
    cout << "makes sense" << endl;
	return 0;
}
