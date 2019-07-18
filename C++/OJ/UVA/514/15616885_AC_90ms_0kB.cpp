#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n, n){
        vector<int> t(1000);
        while(1){
            cin >> t[0];
            if(t[0] == 0){
                cout << endl;
                break;
            }
            for(int i = 1; i < n; i++)  cin >> t[i];
            int current = 1, target = 0;
            stack<int> s;
            while(current <= n){
                s.push(current);
                while(!s.empty() && s.top() == t[target]){
                    s.pop();
                    target++;
                    if(target>=n) break;
                }
                current++;
            }
            (s.empty())? cout << "Yes" << endl : cout << "No" << endl;
        }
    }
    return 0;
}
