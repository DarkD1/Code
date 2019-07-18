#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M, a;
    while(cin >> N >> M){
        int res = 0;
        if(N == 0 && M == 0) break;
        map <int, int> n, m;
        while(N--){
            cin >> a;
            n[a]++;
        }
        while(M--){
            cin >> a;
            m[a]++;
            if(n[a] == m[a]) res++;
        }
        cout << res << endl;
    }
    return 0;
}
