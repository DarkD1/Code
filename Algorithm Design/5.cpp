#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999

int main () {
    int V, mincost = 0, no_edge;
    cin >> V;
    int G[V][V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> G[i][j];
        }
    }

  bool selected[V];
  memset (selected, false, sizeof (selected));
  no_edge = 0;
  selected[0] = true;
  while (no_edge < V - 1) {
      int min = INF, x = 0, y = 0;
      for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
              if (!selected[j] && G[i][j]){
                  if (min > G[i][j]) {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }

              }
          }
        }
      }
      mincost += min;
      selected[y] = true;
      no_edge++;
    }
    cout << mincost << endl;
  return 0;
}
