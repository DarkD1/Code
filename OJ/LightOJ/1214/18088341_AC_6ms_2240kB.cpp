#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);

    int64_t t, d;
    char str[500];
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> str >> d;
        if(d < 0) d *= -1;
        int64_t idx = 0, r = 0;
        if(str[0] == '-') idx = 1;
        for(; idx < strlen(str); idx++){
            r = (r * 10) + (str[idx] - '0');
            r %= d;
//            dbg(r);
        }
        if(r == 0)   cout << "Case " << i << ": divisible" << endl;
        else    cout << "Case " << i << ": not divisible" << endl;
    }
    return 0;
}

