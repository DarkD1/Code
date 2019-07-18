#include<bits/stdc++.h>
using namespace std;
string tolowercase(string x){
    for(int i = 0; i < x.size(); i++) x[i] = tolower(x[i]);
    return x;
}
int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> language;
    vector<string> keyword;
    while(n--){

        string l, t;
        getline(cin, l);

        for(int i = 0; i < l.size(); i++){
            if(l[i] == ' ') {
                language.push_back(t);
                l = l.substr(i+1);
                l = tolowercase(l);
                keyword.push_back(l);
                break;
            }
            else {
                t += l[i];
            }
        }
    }
    map<string , string> mp;
    for(int i = 0; i < language.size(); i++){
            string temp;
        for(int j = 0; j < keyword[i].size(); j++){
            if(keyword[i][j] == ' '){
                mp[temp] = language[i];
                temp = "";
            }
            else {
                temp += keyword[i][j];
            }
        }
        mp[temp] = language[i];

    }
    cin.ignore();
    string s;
    while(getline(cin, s)){
            s = tolowercase(s);
        string temp;
        vector<string> x;
        bool notPrinted = true;
        for(int i = 0; i <= s.size() && notPrinted; i++){
            if(s[i] == ' ' || i == s.size() || s[i] == ',' || s[i] == '.'|| s[i] == '!'|| s[i] == ';' || s[i] == '?'|| s[i] == '(' || s[i] == ')'|| s[i] == '{'|| s[i] == '}' || s[i] == '['|| s[i] == ']'){
                if(mp[temp] != "")    {
                    cout << mp[temp] ;
                    notPrinted = false;
                    break;
                }
                temp = "";

            }
            else {
                temp += s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
/*
4
Vulcan throks kilko-srashiv k’etwel
Romulan Tehca uckwazta Uhn Neemasta
Menk e’satta prah ra’sata
Russian sluchilos

Dif-tor heh, Spohkh. I’tah trai k’etwel
Uhn kan’aganna! Tehca zuhn ruga’noktan!

*/
