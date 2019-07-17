#include <bits/stdc++.h>
using namespace std;

int V;
int graph[100][100];
bool isSafe (int v, int color[], int c){
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(int m, int color[], int v){
    if (v == V) return true;
    for (int c = 1; c <= m; c++){
        if (isSafe(v, color, c)){
           color[v] = c;
           if (graphColoring(m, color, v+1))
             return true;
           color[v] = 0;
        }
    }
    return false;
}


int main(){

    int m;
    cin >> V >> m;
    int color[V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
        color[i] = 0;
    }
    if(graphColoring (m, color, 0)){
        cout << "Assigned Colors are:" << endl;
        for(int i = 0; i < V; i++) cout << color[i] << " ";
    }else{
        cout << "m Coloring is not possible" << endl;
    }
    return 0;
}

/*
        4 3
        {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};

*/
