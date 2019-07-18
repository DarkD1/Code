#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);
    set<char> r;
    string str;
    getline(cin, str);
    for(char c: str){
        if(c >= 'a' && c <= 'z') {
            r.insert(c);
        }
    }
    cout << r.size();
    return 0;
}
