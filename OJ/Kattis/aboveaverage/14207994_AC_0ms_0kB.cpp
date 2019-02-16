#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases, n;
    vector<vector <int> > numbers;
    cin >> cases;
    while(cases--){
        cin >> n;
        vector<int> number;
        while(n--){
            int a;
            cin >> a;
            number.push_back(a);
        }
        numbers.push_back(number);
    }
    for(int i = 0; i < numbers.size(); i++){
        int sum = accumulate(numbers[i].begin(), numbers[i].end(),0);
        int avg_num = sum/numbers[i].size();
        int counter = 0;
        for(int j = 0; j < numbers[i].size(); j++){
            if(avg_num < numbers[i][j]) {
                counter++;
            }
        }
        double d = (counter*100.0)/numbers[i].size();
        printf("%.3f%\n",d);
    }
    return 0;
}
