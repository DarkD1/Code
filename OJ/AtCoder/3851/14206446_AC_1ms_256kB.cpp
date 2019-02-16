#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    s.replace(s.begin(), s.begin()+4, "2018");
    cout << s << endl;
    return 0;
}
