#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, players = 2;
    vector <int> levels;
    cin >> n;
    while(players--){
        cin >> p;
        for(int i = 0 ; i < p; i++){
            int x;
            cin >> x;
            levels.push_back(x);
        }
    }
    sort(levels.begin(), levels.end());
    levels.erase(unique(levels.begin(), levels.end()), levels.end());
    if(levels.size() == n) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;
    return 0;
}
