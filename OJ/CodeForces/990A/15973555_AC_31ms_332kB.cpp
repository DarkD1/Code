#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m, a, b, cost;
    cin >> n >> m >> a >> b;
    cost = min((n%m)*b, (m-n%m)*a);
    cout << cost << endl;
    return 0;
}

