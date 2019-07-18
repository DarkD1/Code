#include<bits/stdc++.h>
using namespace std;

int main(){
    string k, n;
    int sum = 0;
    cin >> k >> n;
    vector<int> v(n.size());
    for(int i = n.size() - 1; i >= 0; i--) v[i] = n[i] - '0';
    for(int i = 0; i < stoi(k) - 1; i++){
        sum += v[i];
        bool golden = true;
        int temp_sum = 0, pos = i + 1;
        while(pos < stoi(k)){
            temp_sum = v[pos++];
            while(pos < stoi(k) && temp_sum + v[pos] <= sum) temp_sum += v[pos], pos++;
            if(temp_sum != sum) golden = false;
        }
        if(golden) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}
