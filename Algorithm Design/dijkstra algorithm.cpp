#include <bits/stdc++.h>
using namespace std;

const int maxVertex = 100, INF = 10e6;
int vertex, graph[maxVertex][maxVertex], dist[maxVertex];
bool spt[maxVertex];

int minimumdist(){
    int mini = INF, minIndex;
    for(int i = 0; i < vertex; i++)
        if(!spt[i] && dist[i] <= mini)
            mini = dist[i], minIndex = i;
    return minIndex;
}
void dijkstra(int src){
    for(int i = 0; i < vertex; i++) dist[i] = INF, spt[i] = false;
    dist[src] = 0;
    for(int i = 0; i < vertex - 1; i++){
        int u = minimumdist();
        spt[u] = true;
        for(int v = 0; v < vertex; v++)
            if(!spt[v] && graph[u][v] && dist[u] != INF)
                dist[v] = min(dist[u] + graph[u][v], dist[v]);
    }

}
int main(){
    cin >> vertex;
    for(int i = 0; i < vertex; i++)
        for(int j = 0; j < vertex; j++)
            cin >> graph[i][j];

    for(int i = 0; i < vertex; i++){
        dijkstra(i);
        for(int j = 0; j < vertex; j++)
            cout << "From Vertex " << i << " to " << j << " minimum distance is: " << dist[j] << endl;
        cout << endl << endl;
    }
    return 0;
}

/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
