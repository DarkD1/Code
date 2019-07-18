#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);

    string str, num;
    int n;
    cin >> str;
    num += str.back();
    str.pop_back();
    if(str.size() > 0)  num += str.back();
    reverse(num.begin(), num.end());
    n = stoi(num);
    if(n % 4 == 0) cout << "4" << endl;
    else cout << "0" << endl;
    return 0;
}