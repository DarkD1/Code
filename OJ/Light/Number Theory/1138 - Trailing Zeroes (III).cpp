#include <bits/stdc++.h>
using namespace std;

long countZero(long n){
    int c = 0;
    for(long i = 5; n / i >= 1; i *= 5) c += n / i;
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &m);
        int start = 0, endd = 10e8, mid;
        bool found = false;
        while(start < endd){
            mid = (start + endd) >> 1;
            long fz = countZero(mid);
            if(fz >= m){
                found |= (m == fz);
                endd = mid;
            }
            else start = mid + 1;
        }
        if(found) cout << "Case " << i << ": " << start << endl;
        else cout << "Case " << i << ": impossible" << endl;

    }
    return 0;
}


