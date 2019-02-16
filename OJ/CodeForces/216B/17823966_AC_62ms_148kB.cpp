#include <bits/stdc++.h>
using namespace std;

int n, m, needToRemove = 0, cnt;
vector<vector<int> > enemy;
vector<bool> visited;

bool dfs(int curr, int parr){
    if(visited[curr]) return true;
    visited[curr] = true;
    for(int child: enemy[curr]){
        if(child != parr){
            cnt++;
            if(dfs(child, curr)) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);

    cin >> n >> m;
    enemy = vector<vector<int> >(n);
    visited = vector<bool>(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        enemy[a - 1].push_back(b - 1);
        enemy[b - 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cnt = 0;
            bool cycle = dfs(i, -1);
            if(cycle) needToRemove += (cnt & 1);
        }
    }
    if((n - needToRemove) & 1) needToRemove++;

    cout << needToRemove << endl;
    return 0;
}