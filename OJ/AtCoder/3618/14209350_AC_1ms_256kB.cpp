#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, tmp;
    cin >> str >> tmp;
    reverse(str.begin(), str.end());
    if(str == tmp) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
