#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) == 1 & n){
        multiset<int> price;
        long long int total = 0;
        while(n--){
            int k;
            cin >> k;
            while(k--){
                int x;
                cin >> x;
                price.insert(x);
            }
            multiset<int>::iterator lowest = price.begin();
            multiset<int>::iterator highest = --price.end();
            total += *highest - *lowest;
            price.erase(lowest);
            price.erase(highest);
        }
        cout << total << endl;
    }
    return 0;
}
