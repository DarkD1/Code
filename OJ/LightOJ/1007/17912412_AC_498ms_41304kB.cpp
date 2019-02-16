#include <bits/stdc++.h>
using namespace std;
const int m = 5000000;
vector<unsigned long long int> phi(m + 1);
inline void p(){
    for(int i = 2; i <= m; i++) phi[i] = i;
    for(int i = 2; i <= m; i++){
        if(phi[i] == i){
            for(int j = i; j <= m; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    for(int i = 2; i <= m; i++) phi[i] *= phi[i];
    for(int i = 1; i <= m; i++) phi[i] += phi[i - 1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    int n, l, r;
    scanf("%d", &n);
    p();
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        printf("Case %i: %llu\n", i, phi[r] - phi[l - 1]);
    }
    return 0;
}
