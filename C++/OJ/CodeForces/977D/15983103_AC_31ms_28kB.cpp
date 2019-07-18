#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int > l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++){
        long long int x = l[i];
        vector<long long int > t;
        t.push_back(x);
            for(int j = 0; j < n-1; j++){
                if(count(l.begin(), l.end(), x/3) > 0 && x % 3 == 0) {
                    t.push_back(x/3);
                    x /= 3;
                }
                else if(count(l.begin(), l.end(), x*2) > 0){
                    t.push_back(x*2);
                    x *= 2;
                }
                else break;

            }

        if(t.size() == n){
            for(int k = 0; k < n; k++) cout << t[k] << " ";
            cout << endl;
            break;
        }
    }
    return 0;
}
