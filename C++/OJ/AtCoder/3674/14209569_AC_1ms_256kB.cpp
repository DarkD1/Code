#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> s;
    cin >> n;
    while(n){
        s.push_back(n%10);
        n/=10;
    }
    if(s[0] == s[1] && s[1] == s[2]) cout << "Yes" << endl;
    else if(s[1] == s[2] && s[2] == s[3]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
