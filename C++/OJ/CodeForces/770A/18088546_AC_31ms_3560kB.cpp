#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int n, k;
    string alphabet = "abcdefghijklmnopqrstuvwxyz", passwordAlphabet;
    cin >> n >> k;
    passwordAlphabet = alphabet.substr(0, k);
    for(int i = 0, j = 0; i < n; i++){
        cout << passwordAlphabet[j++];
        if(j == k) j = 0;
    }
    return 0;
}