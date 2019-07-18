#include <bits/stdc++.h>
using namespace std;
double l[1000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for(int i = 1; i <= 1000000; i++)
        l[i] = l[i - 1] + log(i);
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        int res = (l[a] / log(b)) + 1;
        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}
