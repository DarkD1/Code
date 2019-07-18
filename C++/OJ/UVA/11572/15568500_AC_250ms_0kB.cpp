#include<bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    map<int, int> lastseen;
    scanf("%d", &n);
    vector<int> id(n);
    int res = 0, start = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &id[i]);
      if (lastseen[id[i]] >= start) start = lastseen[id[i]] + 1;
      lastseen[id[i]] = i;
      res = (i - start + 1) > res ? (i - start + 1) : res;
    }
    printf("%d\n", res);
  }
  return 0;
}
