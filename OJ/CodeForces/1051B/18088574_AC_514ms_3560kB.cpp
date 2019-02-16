#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);

    long long l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	for(auto i = 0; i < (r - l) / 2 + 1; i++){
        cout << l + i * 2 << " " << l + i * 2 + 1 << endl;
	}
    return 0;
}