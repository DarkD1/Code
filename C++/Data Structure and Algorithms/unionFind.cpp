#include <bits/stdc++.h>
using namespace std;

const int maxSize = 10e6;
// graph
struct edge{
    int source, destination;
};
int parent[maxSize];
vector<edge> graph;

// parent initialization
void initialize(int n){
    for(int i = 0; i <= n; i++) parent[i] = i;
}
// union find
int findParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}
// Does this graph contain a cycle?
bool isCycle(int n){
    initialize(n);
    for(int i = 0; i < graph.size(); i++){
        int sourceParent = findParent(graph[i].source);
        int destinationParent = findParent(graph[i].destination);
        if(sourceParent == destinationParent)
            return true;
        parent[sourceParent] = destinationParent;
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        edge in;
        cin >> in.source >> in.destination;
        graph.push_back(in);
    }

    if(isCycle(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
