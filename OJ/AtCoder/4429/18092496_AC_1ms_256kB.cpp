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
    string str;
    cin >> str;
    for(char c: str){
        if(c == '1'){
            cout << '9';
        }
        else if(c == '9'){
            cout << '1';
        }
        else {
            cout << c;
        }
    }
    return 0;
}
