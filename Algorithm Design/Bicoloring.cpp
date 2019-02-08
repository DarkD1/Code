#include <bits/stdc++.h>
using namespace std;
#define MAXV 100
enum COLOR{WHITE, RED, GREEN};

int v, e;
vector<int>graph[MAXV];
vector<COLOR> color;

bool bicolor(int src){
    bool ret = true;
    for(int i = 0; i < graph[src].size(); i++){
        if(color[graph[src][i]] != WHITE && color[graph[src][i]] == color[src]){
            return false;
        }
        if(color[graph[src][i]] == WHITE){
            color[graph[src][i]] = color[src] == RED? GREEN : RED;
            ret &= bicolor(color[graph[src][i]]);
        }
    }
    return ret;
}
int main(){
    cin >> v >> e;
    color = vector<COLOR>(v, WHITE);
    for(int i = 0; i < e; i++){
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    color[0] = RED;
    if(bicolor(0)){
        cout << "BICOLORABLE" << endl;
    }
    else{
        cout << "NOT BICOLORABLE" << endl;
    }
    return 0;
}
