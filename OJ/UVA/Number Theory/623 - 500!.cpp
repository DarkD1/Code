#include <bits/stdc++.h>
using namespace std;
#define maxn 1002
#define maxl 2600

int fact[maxn][maxl];
void factorial(){
    fact[0][0] = fact[1][0] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 0; j < maxl; j++){
            fact[i][j] += (fact[i - 1][j] * i);
            if(fact[i][j] > 9){
                fact[i][j + 1] = fact[i][j] / 10;
                fact[i][j] = fact[i][j] % 10;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    factorial();
    int n;
    while(scanf("%d", &n) == 1){
        cout << n << "!" << endl;
        int i;
        for(i = maxl - 1; i >= 0; i--){
            if(fact[n][i] != 0) break;
        }
        for(int l = i; l >= 0; l--){
            cout << fact[n][l];
        }
        cout << endl;
    }
    return 0;
}
