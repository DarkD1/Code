#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    string str, temp = "";
    getline(cin, str);
    vector<int> arr;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+' || str.size() - 1 == i){
            if(str.size() - 1 == i) temp += str[i];
            arr.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp += str[i];
        }
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i];
        if(i < arr.size() - 1) cout << "+";
    }
    return 0;
}