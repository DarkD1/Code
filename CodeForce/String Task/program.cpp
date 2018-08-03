#include <bits/stdc++.h>
using namespace std;

int main(){
    string x, res = "", dot = ".";
    map <char, bool> m = {{'a', true},{'e', true},{'i', true},{'o', true},{'u', true},{'y', true}};
    cin >> x;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    for(char i: x){
        if(!m[i]){
            res += dot + i;
        }
    }
    cout << res << endl;
    return 0;
}
