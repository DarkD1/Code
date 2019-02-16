#include<bits/stdc++.h>
using namespace std;
string toLowerstr(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
vector<string> split(string s){
    vector<string> res;
    string temp;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || i == s.size()-1){
            if(i == s.size()-1) temp += s[i];
            res.push_back(temp);
            temp = "";
        }
        else {
            temp += s[i];
        }
    }
    return res;
}
int main(){
    string str;
    while(getline(cin, str)){
        if(str == "*") break;
        str = toLowerstr(str);
        bool f = true;
        vector<string > words = split(str);
        for(int i = 0; i < words.size()-1; i++){
            if(words[i][0] != words[i+1][0]) {
                f = false;
                break;
            }
        }
        if(f) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}

