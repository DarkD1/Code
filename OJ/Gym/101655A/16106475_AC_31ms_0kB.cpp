#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        int c = 0;
        vector<vector<int> > ship(n);
        for(int i = 0; i < n; i++) {
            vector<int> temp(3);
            for(int i = 0; i < 3; i++) cin >> temp[i];
            float x, y;
            x = temp[1] * 1.0 / temp[2];
            y = temp[0] * x;
            if(y >= d) c++;
        }
        cout << c << endl;
    }
    return 0;
}
