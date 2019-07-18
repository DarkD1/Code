#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    uint64_t l1, r1, l2, r2;
    while(n--){
        cin >> l1 >> r1 >> l2 >> r2;
        uint64_t l = (l1 + r1) / 2;
        uint64_t r = (l2 + r2) / 2;
        if(l == r) cout << l << " " << r + 1 << endl;
        else cout << l << " " << r << endl;
    }
    return 0;
}