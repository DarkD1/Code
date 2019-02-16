#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, c = 0;
    cin >> n;
    vector<int> v(n);
    int answer = n, pt = n / 2;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++){
        while(true){
            if(v[i] * 2 <= v[pt]){
                pt++, answer--;
                break;
            }
            else pt++;
            if(pt == n) break;
        }
        if(pt == n) break;
    }
    cout << answer;
    return 0;
}
