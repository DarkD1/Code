#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
#define MOD 100007
struct data{
    int64_t product;
};
int arr[MAXN];
data tree[MAXN * 4];
int pdct = 1;
void build(int node, int beg, int endd){
    if(beg == endd){
        tree[node].product = arr[beg];
        return;
    }
    int left = (node << 1), right = (node << 1) + 1, mid = (beg + endd) >> 1;
    build(left, beg, mid);
    build(right, mid + 1, endd);
    tree[node].product = 1LL * (tree[left].product * tree[right].product) % MOD;
}
void query(int node, int beg, int endd, int x, int y){
    if(endd < x || beg > y) return;
    if(beg >= x && endd <= y){
        pdct *= tree[node].product;
        return;
    }
    int left = (node << 1), right = (node << 1) + 1, mid = (beg + endd) >> 1;
    query(left, beg, mid, x, y);
    query(right, mid + 1, endd, x, y);
}
void update(int node, int beg, int endd, int x, int val){
    if(endd < x || beg > x) return;
    if(beg == x && endd == x){
        tree[node].product = val;
        return;
    }
    int left = (node << 1), right = (node << 1) + 1, mid = (beg + endd) >> 1;
    update(left, beg, mid, x, val);
    update(right, mid + 1, endd, x, val);
    tree[node].product = 1LL * (tree[left].product * tree[right].product) % MOD;
}
int main(){
    int n, q;
    while(scanf("%d %d", &n, &q) == 2){
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        build(1, 1, n);
        while(q--){
            pdct = 1;
            getchar();
            char c; int a, b;
            scanf("%c %d %d", &c, &a, &b);
            if(c == 'C'){
                update(1, 1, n, a, b);
            }
            if(c == 'P'){
                query(1, 1, n, a, b);
                if(pdct == 0){
                    printf("0");
                }else if(pdct > 0){
                    printf("+");
                }else{
                    printf("-");
                }
            }
        }
        puts("");
    }
    return 0;
}
