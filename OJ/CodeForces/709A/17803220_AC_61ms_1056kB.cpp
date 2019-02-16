#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "w", stdout);
    int n, b, d, temp, times = 0, sum = 0;
    vector<int> orange;
    cin >> n >> b >> d;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp <= b) orange.push_back(temp);
    }
    for(int i: orange){
        sum += i;
        if(sum > d) times++, sum = 0;
    }
    cout << times << endl;
    return 0;
}
