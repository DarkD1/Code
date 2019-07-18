#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int64_t N;
    cin >> N;
    for(int64_t i = N; ; i++){
        string str = to_string(i);
        set<char> s;
        for(char c: str) s.insert(c);
        if(s.size() == 1){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

