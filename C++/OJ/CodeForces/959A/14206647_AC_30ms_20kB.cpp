#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i = 0;
    cin >> n;
    while(n>2){
        if(i%2 == 0)  {
            int temp = (n%2==0)? n-2: n-1;
            n-=temp;
        }
        else {
            int temp = (n%2==0)? n-1: n-2;
            n-=temp;
        }
        i++;
    }
    if(n == 2) cout << "Mahmoud" << endl;
    else if(n==1) cout << "Ehab" << endl;
    return 0;
}
