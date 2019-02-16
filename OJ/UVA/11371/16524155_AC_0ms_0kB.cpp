#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    while(cin >> n){
        string num = n, r;
        long long int t = 0, d = 0, div = 0, N = 0;
        sort(num.begin(), num.end());
        r = num;
        reverse(r.begin(), r.end());
        for(int i = 0; i < num.size(); i++){
            if(num[i] == '0' && num[i+1] != '0') {
                swap(num[0], num[i+1]);
                break;
            }
        }
        stringstream S(num);
        S >> N;
        stringstream s(r);
        s >> t;
        d = t - N;
        div = d / 9;
        cout << t << " - " << num << " = " << d << " = 9 * " << div << endl;
    }
    return 0;
}

