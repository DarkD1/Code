#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<string, int>&a, const pair<string, int>&b)
{
   return a.second<b.second;
}
int main(){
    string s;
    int n;
    map<string, int> m;
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size() - 1; i++) {
        string t = s.substr(i, 2);
        m[t]++;
    }
    map<string, int>::iterator it = max_element(m.begin(), m.end(), compare);
    cout << it->first << endl;
    return 0;
}