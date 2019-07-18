#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int a_jon = count(a.begin(), a.end(), 'a');
    int a_doc = count(b.begin(), b.end(), 'a');
    if(a_jon >= a_doc) cout << "go" << endl;
    else cout << "no" << endl;
    return 0;
}
