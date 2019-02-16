#include <bits/stdc++.h>
using namespace std;
int print(int i){
    if(i == 1 || i == 2) return 1;
    return print(i - 1) + print(i - 2);
}
int main(){
    int n;
    cin >> n;
    cout << print(n);
    return 0;
}
