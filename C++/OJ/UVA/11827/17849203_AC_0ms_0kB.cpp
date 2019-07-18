#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    string str;
    int n, res = 0, val;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, str);
        res = 0;
        vector<int> v;  istringstream s(str);
        while(s >> val)
            v.push_back(val);
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                res = max(res, __gcd(v[i], v[j]));
            }
        }
        cout << res << endl;
    }
    return 0;
}
