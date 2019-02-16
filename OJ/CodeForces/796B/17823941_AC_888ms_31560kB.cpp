#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q, last = 1;
    map<int, bool> hole;
    cin >> n >> m >> q;
    while(m--){
        int x; cin >> x;
        hole[x] = true;
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == last && (!hole[a])) last = b;
        else if(b == last && (!hole[b])) last = a;
    }
    cout << last << endl;
    return 0;
}