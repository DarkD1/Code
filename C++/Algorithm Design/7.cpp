#include <bits/stdc++.h>
using namespace std;
#define INF 9999
int main(){
    int v;
    cin >> v;
    int graph[v][v], a[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0 && i != j) a[i][j] = INF;
            else a[i][j] = graph[i][j];
        }
    }
    cout << endl << endl;
    cout << "A - 0" << endl << endl;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(int k = 0; k < v; k++){
            cout << "A - " << k + 1 << endl;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                if(a[i][j] == INF) cout << "INF ";
                else cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    return 0;
}

