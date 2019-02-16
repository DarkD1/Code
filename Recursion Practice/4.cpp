#include <bits/stdc++.h>
using namespace std;
void print(int i, int n){
    if(i > n)
        return;
    if(i == 1){
        cout << "1";
    }else if(i == 2){
        cout << "x";
    }else{
        cout << "x^" << i - 1;
    }
    if(i != n){
        cout << " + ";
    }
    print(i + 1, n);
}
int main(){
    int n;
    cin >> n;
    print(1, n);
    return 0;
}


