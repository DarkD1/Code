#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j = 0; j < n; j++) cin >> v[j];
        sort(v.begin(), v.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            for(int k = i + 1; k < n; k++){
                int l = lower_bound(v.begin(), v.end(), v[i]+v[k]) - v.begin();
                res += (l - k - 1);
            }
        }
        printf("Case %d: %lld\n", t, res);
    }
    return 0;
}
