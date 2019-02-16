#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        n = str.size();
        if(n <= 10) cout << str << '\n';
        else cout << str[0] << n - 2 << str.back() << '\n';
    }
    return 0;
}
