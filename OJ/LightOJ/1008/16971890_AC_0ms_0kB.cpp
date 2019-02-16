#include<bits/stdc++.h>
using namespace std;
int main(){
    uint64_t S;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        uint64_t row, col;
        cin >> S;
        uint64_t p = round(sqrtl(S));
        if(p * p >= S){
            col = p * p - S + 1;
            row = p;
        }
        else {
            col = S - p * p;
            row = p + 1;
        }
        if(p & 1) swap(row, col);
        printf("Case %d: %lld %lld\n", i, row, col);
    }
    return 0;
}
