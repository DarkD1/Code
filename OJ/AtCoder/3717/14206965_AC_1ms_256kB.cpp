#include <bits/stdc++.h>
using namespace std;

int main(){
    int counter = 0, n;
    cin >> n;
    while(n){
        if(n%10 == 1) counter++;
        n/=10;
    }
    cout << counter << endl;
    return 0;
}
