#include <bits/stdc++.h>
using namespace std;
int play(int a, int b){
    if(!b) return 0;
    if(a / b > 1) return 1;
    return play(b, a - b) + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    long long a, b;
    while(scanf("%lld%lld", &a, &b)){
        if(a == 0 && b == 0) break;
        int cnt = play(max(a, b), min(a, b));

        if(cnt & 1) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }
    return 0;
}
