#include<bits/stdc++.h>
using namespace std;
int main(){
    uint64_t n, x, y, white, black;
    cin >> n >> x >> y;
    white = (x - 1) + (y - 1);
    black = (n - x) + (n - y);
    if(white <= black) cout << "White";
    else cout << "Black";
    return 0;
}
