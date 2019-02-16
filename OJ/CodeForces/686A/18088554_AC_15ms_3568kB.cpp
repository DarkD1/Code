#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    uint64_t n, init, distress = 0;
    cin >> n >> init;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        char c;
        int val;
        cin >> c >> val;
        if(c == '+') init += val;
        else    val > init? distress++:init -= val;
    }
    cout << init << " " << distress;
    return 0;
}