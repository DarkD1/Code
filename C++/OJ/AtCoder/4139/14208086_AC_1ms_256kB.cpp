#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    long long int mul = a*b, add = a+b, sub = a-b;
    vector<long long int> num = {mul, add, sub};
    cout << *std::max_element(num.begin(), num.end()) << endl;
    return 0;
}
