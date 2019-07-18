#include <bits/stdc++.h>
using namespace std;
#define MAXN 100007
int ans;
char tree[MAXN * 4];
int toggle[MAXN * 4];
char arr[MAXN];
void init(int node, int beg, int endd){
    if(beg == endd){
        tree[node] = arr[beg];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (beg + endd) >> 1;
    init(left, beg, mid);
    init(right, mid + 1, endd);
    toggle[node] = toggle[left] = toggle[right] = 0;
}
void update(int node, int beg, int endd, int x, int y){
    if(x > endd || y < beg) return;
    if(beg >= x && endd <= y){
        toggle[node]++;
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (beg + endd) >> 1;
    update(left, beg, mid, x, y);
    update(right, mid + 1, endd, x, y);
}
void query(int node, int beg, int endd, int x, int counter = 0){
    counter += toggle[node];
    if(x > endd || x < beg) return;
    if(beg == x && endd == x){
        ans = tree[node] - '0';
//        cout << "CNT: "<< counter << endl;
        if(counter & 1) ans = 1 - ans;
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (beg + endd) >> 1;
    query(left, beg, mid, x, counter);
    query(right, mid + 1, endd, x, counter);
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
//        memset(toggle, 0, sizeof(toggle));
        printf("Case %d:\n", i);
        int n, q;
        scanf("%s", arr + 1);
        n = strlen(arr + 1);
        init(1, 1, n);
        scanf("%d", &q);
        while(q--){
            getchar();
            char c; int i, j;
            scanf("%c", &c);
            if(c == 'I'){
                scanf("%d %d", &i, &j);
                update(1, 1, n, i, j);
            }
            else if(c == 'Q'){
                scanf("%d", &i);
                query(1, 1, n, i);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
