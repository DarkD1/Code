#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        if(i > 0) cout << endl;
        int B, SG, SB;
        cin >> B >> SG >> SB;
        multiset<int> green, blue;
        while(SG--){
            int x;
            cin >> x;
            green.insert(x);
        }
        while(SB--){
            int x;
            cin >> x;
            blue.insert(x);
        }
        while(!green.empty() && !blue.empty()){
                vector<int> a, b;
                int m = min(B, min(int(green.size()), int(blue.size())));
                for(int i = 0; i < m; i++){
                    if(!green.empty()){
                        multiset<int>::iterator x = --green.end();
                        a.push_back(*x);
                        green.erase(x);
                    }
                    if(!blue.empty()){
                        multiset<int>::iterator x = --blue.end();
                        b.push_back(*x);
                        blue.erase(x);

                    }
                }
                for(int i = 0; i < m; i++){
                    if(a[i] > b[i]){
                        int x = a[i], y = b[i];
                        green.insert(x - y);
                    }
                    else if(b[i] > a[i]){
                        int x = a[i], y = b[i];
                        blue.insert(y - x);
                    }
                }
                if(blue.empty() && green.empty()){
                    cout << "green and blue died" << endl;
                    break;
                }
                else if(green.empty()){
                    cout << "blue wins" << endl;
                    multiset<int>::reverse_iterator x;
                    for(x = blue.rbegin(); x != blue.rend(); x++){
                        cout << *x << endl;
                    }
                }
                else if(blue.empty()){
                    cout << "green wins" << endl;
                    multiset<int>::reverse_iterator y;
                    for(y = green.rbegin(); y != green.rend(); y++){
                        cout << *y << endl;
                    }
                }
            }
        }
        return 0;
}


