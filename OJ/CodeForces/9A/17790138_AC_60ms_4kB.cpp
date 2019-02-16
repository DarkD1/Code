#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);

    int y, w;
    const string p[7] = {"", "1/1", "5/6", "2/3", "1/2", "1/3", "1/6"};
    cin >> y >> w;
    cout << p[max(y, w)] << endl;
    return 0;
}
