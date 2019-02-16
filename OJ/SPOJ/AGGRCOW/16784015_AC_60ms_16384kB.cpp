#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
int main(){
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        ll n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for(int j = 0; j < n; j++) cin >> arr[j];
        sort(arr.begin(), arr.end());
        ll low = 1, high = 1000000001, ans = 0;

        while(low <= high){
            ll f = arr[0], temp = 1, mid = (low + high) / 2;
            for(int k = 1; k < n; k++){
                if(arr[k] - f >= mid) temp++, f = arr[k];
            }
            if(temp < c) high = mid - 1;
            else ans = mid, low = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
