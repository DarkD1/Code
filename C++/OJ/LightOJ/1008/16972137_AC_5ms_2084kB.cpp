#include<bits/stdc++.h>
using namespace std;
pair<uint64_t, uint64_t> fantabulousBirthday(uint64_t S){
    uint64_t row, col, p = round(sqrtl(S));
    p * p >= S? col = p * p - S + 1 : col = S - p * p;
    p * p >= S? row = p : row = p + 1;
    return p & 1? make_pair(col, row) : make_pair(row, col);
}
int main(){
    uint64_t S;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        uint64_t row, col;
        cin >> S;
        pair<uint64_t, uint64_t > ans = fantabulousBirthday(S);
        printf("Case %d: %lld %lld\n", i, ans.first, ans.second);
    }
    return 0;
}
