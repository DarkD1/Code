#include <bits/stdc++.h>
using namespace std;
#define mx 100007
int arr[mx], tree[mx * 4];
void init(int node, int b, int e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] > tree[right]? tree[right] : tree[left];
}
int query(int node, int b, int e, int i, int j){
    if(i > e || b > j){
        return mx;
    }
    if(b >= i && e <= j){
        return tree[node];
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
//    cout << left << " " << right << " " << mid << endl;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 > p2? p2 : p1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
//    cin >> t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
//        cout << "Case " << i + 1 << ":" << endl;
        printf("Case %d:\n", i + 1);
        int n, q;
//        cin >> n >> q;
        scanf("%d%d", &n, &q);
        for(int j = 0; j < n; j++){
//          cin >> arr[j];
            scanf("%d", &arr[j]);
        }
        init(1, 0, n - 1);
        for(int j = 0; j < q; j++){
            int f, l;
//            cin >> f >> l;
            scanf("%d%d", &f, &l);
            int res = query(1, 0, n - 1, f - 1, l - 1);
//            cout << res << endl;
            printf("%d\n", res);
        }
    }
}

