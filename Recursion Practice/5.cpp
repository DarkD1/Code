#include <bits/stdc++.h>
using namespace std;
int print(int base, int i, int n){
    if(i == n)
        return 0;
    return pow(base, i) + print(base, i + 1, n);
}
int main(){
    int x, n;
    cin >> x >> n;
    cout << print(x, 0, n);
    return 0;
}



