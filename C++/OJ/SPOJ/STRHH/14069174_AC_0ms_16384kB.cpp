#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    vector <string> p;
    cin >> n;
    for(int i = 0 ; i <= n ; i++){
        string x;
        getline(cin,x);
        p.push_back(x);
    }
    for(int i = 0; i <= n; i++){
        string a;
        for(int j = 0; j < p[i].size()/2; j+=2) {
            a+=p[i][j];
        }
        cout << a << endl;
    }
}
