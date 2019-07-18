#include<bits/stdc++.h>
using namespace std;
bool comp(char a, char b){
    if(tolower(a) == tolower(b)) return a < b;
    return tolower(a) < tolower(b);
}
int main(){
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        sort(str.begin(), str.end(), comp);
        do{
            cout << str << endl;
        }while(next_permutation(str.begin(), str.end(), comp));
    }
    return 0;
}
