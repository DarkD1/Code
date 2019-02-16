#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    while(N--){
        string temp, res = "", num1, num2;
        bool f1 = true;
        int carry = 0;

        cin >> num1 >> num2;
        int m = max(num1.size(), num2.size());
        for(int i = num1.size() - 1; i < m; i++){
            if(i == m - 1) break;
            num1 += '0';
        }
        for(int i = num2.size() - 1; i < m; i++){
            if(i == m - 1) break;
            num2 += '0';
        }
        for(int i = 0; i < m; i++){
            int c = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = c > 9;
            temp += to_string(c % 10);
        }
        if(carry) temp += '1';
        for(int i = 0; i < temp.size(); i++){
            if(f1 && temp[i] == '0') continue;
            else{
                f1 = false;
                res += temp[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}
