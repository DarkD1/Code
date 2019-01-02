#include <bits/stdc++.h>
using namespace std;

const int maxSize = 10e6;
// graph
struct edge{
    int source, destination, weight;
};
int parent[maxSize], mstValue = 0;
vector<edge> graph, output;
// user defined sorting
bool comp(edge a, edge b){
    return a.weight < b.weight;
}
// parent initialization
void initialize(int n){
    for(int i = 0; i <= n; i++) parent[i] = i;
}
// union find
int findParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}
// krushkal algorithm
void krushkalAlgorithm(int n){
    sort(graph.begin(), graph.end(), comp);
    initialize(n);
    for(int i = 0; i < graph.size(); i++){
        if(output.size() == n - 1) break;
        int sourceParent = findParent(graph[i].source);
        int destinationParent = findParent(graph[i].destination);
        if(sourceParent != destinationParent){
            output.push_back(graph[i]);
            parent[sourceParent] = destinationParent;
            mstValue += graph[i].weight;
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        edge in;
        cin >> in.source >> in.destination >> in.weight;
        graph.push_back(in);
    }
    krushkalAlgorithm(n);
    // result
    cout << "MST Value: " << mstValue << endl;
    for(int i = 0; i < output.size(); i++)
        cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
    return 0;
}
