#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<uint64_t> v = {0};
    int k;

  for(int i = 2; ; i++){
            int n = i*9+1;
            stringstream g;
            g << n;
            string num = g.str();
        int sum = 0;
        for(int j = 0; j < num.size(); j++){
            sum += (num[j] - '0');
        }
        if(sum == 10) v.push_back(i*9+1);
        if(v.size() == 10001) break;
    }
    cin >> k;
    cout << v[k] << endl;
    return 0;
}

