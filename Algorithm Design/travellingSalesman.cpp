#include <bits/stdc++.h>
using namespace std;
#define maxn 100
int v, e;
int graph[maxn][maxn];
vector<int> path;

int dfs(int source){
    int cost = INT_MAX;

    vector<int> vertex;
    for(int i = 0; i < v; i++)
        if(i != source)
            vertex.push_back(i);

    do{
        int c = 0, k = source;
        for(int i = 0; i < vertex.size(); i++){
            c += graph[k][vertex[i]];
            k = vertex[i];
        }
        c += graph[k][source];

        if(c < cost){
            path = vertex;
            path.insert(path.begin(), source);
            path.push_back(source);
            cost = c;
        }

    }while(next_permutation(vertex.begin(), vertex.end()));

    return cost;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int a, b, c;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }
    int cost = dfs(0);
    cout << "Minimum Cost: " << cost << endl;
    cout << "Path: ";
    for(int i: path) cout << i + 1 << " ";
    cout << endl;
    return 0;
}
