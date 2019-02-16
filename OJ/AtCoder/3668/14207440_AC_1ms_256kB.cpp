#include <bits/stdc++.h>
using namespace std;

int main(){
    map <char, int> m = {{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
    char a, b;
    cin >> a >> b;
    if(m[a] > m[b]) cout << ">" << endl;
    else if(m[a] < m[b]) cout << "<" << endl;
    else cout << "=" << endl;
    return 0;
}
