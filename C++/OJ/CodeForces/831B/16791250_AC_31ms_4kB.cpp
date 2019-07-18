#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < c.size(); i++){
           if(c[i] - '0' >= 0 && c[i]-'0' <= 9) {
			cout << c[i];
			continue;
           }
        char t = tolower(c[i]);
        bool up = false;
        if(isupper(c[i])) up = true;
        int pos = a.find(t);
        if(up) {
			char temp = toupper(b[pos]);
			cout << temp;
        }
        else cout << b[pos];
    }
	return 0;
}
