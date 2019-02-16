#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int t;
    cin >> t;
    while(t--){
    cin >> n;
    vector<long long int> x;
    x.push_back(1);
    x.push_back(1);
    for(int i = 2, j = 0; i <= n; i++){
        if(i < 4) {
                long long int sum = accumulate(x.begin(), x.end(), 0);
            x.push_back(sum);
        }
        else {
            long long int sum = 0;
            for(int k = 0; k < 4; k++){
                sum += x[j+k];
            }
            x.push_back(sum);
            j++;
        }
    }
    cout << x[n] << endl;
    }
    return 0;
}
/*
1, 1, 2, 4, 8, 15, 29, 56

*/
