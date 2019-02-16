#include<bits/stdc++.h>
using namespace std;
#define THE using
#define DARK namespace
#define ONE std
#define dbg(x) cout << #x << " = " << x << endl

THE DARK ONE;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int d;
    cin >> d;
    switch(d){
        case 25 :{
            cout << "Christmas" << endl;
            break;
        }
        case 24 :{
            cout << "Christmas Eve" << endl;
            break;
        }
        case 23 :{
            cout << "Christmas Eve Eve" << endl;
            break;
        }
        case 22 :{
            cout << "Christmas Eve Eve Eve" << endl;
            break;
        }
    }
    return 0;
}

