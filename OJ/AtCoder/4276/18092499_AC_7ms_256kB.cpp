#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;
int64_t N, c;
void dfs(uint64_t n){
    if(n > N){
        return;
    }
    dfs(n * 10 + 7);
    dfs(n * 10 + 5);
    dfs(n * 10 + 3);
    string num = to_string(n);
    int cnt7 = 0, cnt5 = 0, cnt3 = 0;
    for(char c: num){
        switch(c){
            case '7':{
                cnt7++;
                break;
            }
            case '5':{
                cnt5++;
                break;
            }
            case '3':{
                cnt3++;
                break;
            }
        }
    }
    if(cnt7 > 0 && cnt5 > 0 && cnt3 > 0){
        c++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    cin >> N;
    dfs(7);
    dfs(5);
    dfs(3);
    cout << c << endl;
    return 0;
}

