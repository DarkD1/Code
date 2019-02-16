#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k;
    vector<int> l(n);
    for(int i = 0; i < n; i++)  scanf("%d", &l[i]);
    sort(l.begin(),l.end());

    if(k == 0 && l[0] > 1)  cout << "1" << endl;
    else if(k == 0 && l[0] == 1)    cout << "-1" << endl;
    else if(k <= n-1) (l[k-1] != l[k])?   cout << l[k-1] << endl : cout << "-1" <<endl;
    else if(k == n)   cout << l[n-1] << endl;

    return 0;
}
