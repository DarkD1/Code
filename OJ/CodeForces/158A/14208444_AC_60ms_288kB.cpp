#include <bits/stdc++.h>
using namespace std;

int main() {
    int p[100], n, k, maxi, counter = 0;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i){
        scanf("%d",&p[i]);
        if(i+1 == k)    maxi = p[i];
    }
    for (int i = 0; i < n; i++)   if(p[i] >= maxi && p[i] > 0)    counter++;
    cout << counter << endl;
    return 0;

}
