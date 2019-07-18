#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector <string> words;
    cin >> n;
    while(n--){
        char x[110];
        scanf("%s",x);
        words.push_back(x);
    }
    for(int i = 0; i < words.size(); i++){
        if(words[i].size() < 11) cout << words[i] << endl;
        else {
            int s = words[i].size() - 2;
            cout << words[i][0] << s << words[i][words[i].size()-1] << endl;
        }
    }
    return 0;
}
