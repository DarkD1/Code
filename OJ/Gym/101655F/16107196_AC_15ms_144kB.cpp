#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == -1) break;
        vector<int> v;
        for(int i = 1 ; i <= n/2; i++) if(n % i == 0) v.push_back(i);
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum == n) {
            cout << n << " = ";
            for(int i = 0; i < v.size(); i++) {
                if(i != v.size()-1) cout << v[i] << " + ";
                else cout << v[i];
            }
        }
        else {
            cout << n << " is NOT perfect.";
        }
        cout << endl;
    }
    return 0;
}
