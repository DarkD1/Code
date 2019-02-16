#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    vector<int> v(5);
    map <vector<int>, int> m;
    while(scanf("%d",&t) && t){
        m.clear();
        for(int i = 0; i < t; i++){
            for(int j = 0; j < 5; j++) cin >> v[j];
            sort(v.begin(), v.end());
            m[v]++;
        }
        int r = 0, maximum = 0;
        for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second == maximum) r += it->second;
            else if (it->second > maximum)  maximum = it->second, r = it->second;
        }
        cout << r << endl;
    }
    return 0;
}
