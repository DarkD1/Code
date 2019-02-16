#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin >> a;
    int x = count(a.begin(), a.end(), 'o');
    cout << 700 + x*100 << endl;
    return 0;
}
