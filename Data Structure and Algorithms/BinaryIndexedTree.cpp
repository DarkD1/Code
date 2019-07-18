#include <bits/stdc++.h>
using namespace std;
#define mx 200005
int arr[mx], tree[mx];

void update(int idx, int val, int n){
  while(idx <= n){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
int query(int idx){
  int sum = 0;
  while(idx){
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
      update(i, arr[i], n);
    }
    int p = 5, q = 3;
    cout << query(p) - query(q - 1) << endl;
    return 0;
}
