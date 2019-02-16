#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    cin.ignore();
    while(N--){
        string str;
        getline(cin, str);
        stringstream s(str);
        int a; vector<int> arr;
        while(s >> a) arr.push_back(a);
        int G = 0;
        for(int i = 0; i < arr.size(); i++) for(int j = i+1; j < arr.size(); j++)   G = max(G, __gcd(arr[i], arr[j]));
        cout << G << endl;
    }
    return 0;
}


