#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    int t = 0;
    while(cin >> input){
        t++;
        if(input == "end") break;
        vector<int> d(10000);
        for(int i=0; i < input.size(); i++){
            d[i] = 1;
            for(int j = 0; j < i; j++)    if(input[j] < input[i])   d[i] = max(d[i],d[j]+1);
        }
        printf("Case %d: %d\n", t, *std::max_element(d.begin(), d.begin() + input.size()));
    }
    return 0;
}
