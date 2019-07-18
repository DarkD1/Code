#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int G, L, a, b;
        cin >> G >> L;
        a = G;
        if(L % G != 0){
            cout << "-1" << endl;
            continue;
        }
        b = L;
        cout << a << " " << b << endl;
    }
    return 0;
}
