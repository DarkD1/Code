#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, t, res = 0;
    cin >> x >> t;
    if(x <= t) cout << res << endl;
    else {
        res = abs(x-t);
        cout << res << endl;
    }
    return 0;

}
