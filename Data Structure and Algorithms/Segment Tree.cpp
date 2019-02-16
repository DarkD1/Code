#include <bits/stdc++.h>
using namespace std;
#define mx 8
int arr[mx] = {0, 4,-9,3,7,1,0,2};
int tree[4 * mx];
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
    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j){
    if(i > e || b > j){
        return 0;
    }
    if(b >= i && e <= j){
        return tree[node];
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int idx, int value){
    if(idx > e || b > idx) return;
    if(b >= idx && e <= idx){
        tree[node] = value;
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, idx, value);
    update(right, mid + 1, e, idx, value);
    tree[node] = tree[left] + tree[right];
}
int main(){
    init(1, 0, 6);
    cout << query(1, 0, mx - 1, 1, 7);
    return 0;
}
