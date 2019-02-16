#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    float n, t, a, curr = 0, mi = 1000, idx;
    cin >> n >> t >> a;
    vector<float> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        curr = t - (v[i] * .006);
        float diff = abs(a - curr);
        if(diff < mi){
            mi = diff;
            idx = i + 1;
        }
    }
    cout << idx << endl;
    return 0;
}



