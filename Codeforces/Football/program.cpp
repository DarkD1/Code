#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    bool flag = true;
    cin >> x;
    for(auto i = 0; i < x.size() - 1; i++){
        int counter = 1;
        if(x[i] == x[i+1]){
            while(x[i] == x[i+1]){
                counter++;
                i++;
            }
        }
        if(counter >= 7){
            flag = false;
            cout << "YES" << endl;
            break;
        }
    }
    if(flag)cout << "NO" << endl;
    return 0;
}

