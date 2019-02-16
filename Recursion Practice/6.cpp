#include <bits/stdc++.h>
using namespace std;
int print(int i){
    if(i == 0 || i == 1) return 1;
    return i * print(i - 1);
}
int main(){
    int n;
    cin >> n;
    cout << print(n);
    return 0;
}




