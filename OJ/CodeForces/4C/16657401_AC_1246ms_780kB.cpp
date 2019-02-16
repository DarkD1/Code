#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> mp;
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        cin >> str;
        mp[str]++;
        if(mp[str] > 1){
            cout << str<<mp[str]-1<<endl;
        }
        else cout << "OK" << endl;
    }
    return 0;
}
