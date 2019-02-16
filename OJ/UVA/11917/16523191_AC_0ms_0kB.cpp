#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, d;
        string duesub;
        cin >> n;
        vector<string> subName(n);
        vector<int> days(n);
        map<string, int> mp;
        for(int j = 0; j < n; j++){
            cin >> subName[j];
            cin.ignore();
            cin >> days[j];
            mp[subName[j]] = days[j];
        }
        cin >> d;
        cin >> duesub;
        cin.ignore();
        if(mp.find(duesub) == mp.end() || mp[duesub] > d+5) cout << "Case " << i << ": Do your own homework!" << endl;
        else if(mp[duesub] <= d) cout << "Case " << i << ": " << "Yesss" << endl;
        else cout << "Case " << i << ": " << "Late" << endl;
    }
    return 0;
}


