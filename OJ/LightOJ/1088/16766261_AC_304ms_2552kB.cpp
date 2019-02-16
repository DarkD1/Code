#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, q, n;
    scanf("%d", &t);

    for(int a = 1; a <= t; a++){
        scanf("%d", &n);
        scanf("%d", &q);
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
            printf("Case %d:\n", a);
        for(int i = 0; i < q; i++){
            int A, B;
            scanf("%d%d", &A, &B);
            int x = lower_bound(v.begin(), v.end(), A) - v.begin(), y = upper_bound(v.begin(), v.end(), B) - v.begin();
            printf("%d\n", y - x);
        }
    }
    return 0;
}
