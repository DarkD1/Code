#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
int mx, mn;
struct data{
    int mxx, mnn;
};
int arr[MAXN];
data sTree[MAXN * 4];
void init(int node, int beg, int endd){
    if(beg == endd){
        sTree[node].mxx = arr[beg];
        sTree[node].mnn = arr[beg];
        return;
    }
    int left = (node << 1), right = (node << 1) + 1, mid = (beg + endd) >> 1;
    init(left, beg, mid);
    init(right, mid + 1, endd);
    sTree[node].mxx = max(sTree[left].mxx, sTree[right].mxx);
    sTree[node].mnn = min(sTree[left].mnn, sTree[right].mnn);
}
void query(int node, int beg, int endd, int x, int y){
    if(x > endd || beg > y){
        return;
    }
    if(beg >= x && endd <= y){
        mx = max(mx, sTree[node].mxx);
        mn = min(mn, sTree[node].mnn);
        return;
    }
    int left = (node << 1), right = (node << 1) + 1, mid = (beg + endd) >> 1;
    query(left, beg, mid, x, y);
    query(right, mid + 1, endd, x, y);
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int n, d, ansMx = INT_MIN, ansMn = INT_MAX, res = INT_MIN;
        scanf("%d %d", &n, &d);
        for(int k = 1; k <= n; k++){
            scanf("%d", &arr[k]);
        }
        init(1, 1, n);
        int beg = 1, endd = d;
        for(int k = 1;; k++){
            mx = INT_MIN, mn = INT_MAX;
            query(1, 1, n, beg, endd);
            res = max(res , mx - mn);
            beg++;
            endd++;
            if(endd > n) break;
        }
        printf("Case %d: %d\n", i, res);
    }
    return 0;
}

