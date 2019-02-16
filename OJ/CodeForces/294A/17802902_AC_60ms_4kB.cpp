#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);
    int n, m, x, y;
    vector<int> a;
    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    while(m--){
        cin >> x >> y;
        int current = a[x - 1];
        int addUpper = y - 1, addLower = current - y;
        if(x != 1 && x != n)  a[x - 2] += addUpper, a[x] += addLower;
        else if(x == 1) a[x] += addLower;
        else if(x == n) a[x - 2] += addUpper;
        a[x - 1] = 0;
    }
    for(int i: a){
        cout << i << endl;
    }
    return 0;
}
