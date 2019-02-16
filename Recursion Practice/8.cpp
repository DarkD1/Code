#include <bits/stdc++.h>
using namespace std;
bool print(int i, int n){
    if(n > 1){
        if(i != n && n % i == 0) return false;
        if(i * i > n) return true;
        return print(i + 1, n);
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << boolalpha << print(2, n);
    return 0;
}

