#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
#define mx 8

int arr[mx] = {0, 4,-9,3,7,1,0,2};
struct info {
    i64 prop, sum;
} tree[mx * 4];
void init(int node, int b, int e){
    if(b == e){
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prop = 0;
}
int query(int node, int b, int e, int i, int j, int carry = 0){
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
void update(int node, int b, int e, int i, int j, i64 x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}
int main(){
    init(1, 0, 6);
    cout << query(1, 0, mx - 1, 1, 7);
    return 0;
}

