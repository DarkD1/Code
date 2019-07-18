#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, a = 0, b = 0, answer = 0, t = 0;
    string str;
    cin >> n >> k >> str;
    for(int i = 0; i < n; i++){
        str[i] == 'a'? a++ : b++;
        if(min(a, b) > k){
            str[t] == 'a'? a-- : b--;
            t++;
        }
        else answer = max(answer, a+b);
    }
    return cout << answer , 0;
}

