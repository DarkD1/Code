#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum_left = 0, sum_right = 0;
    vector <int> numbers;
    for(int i = 0; i < 4; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    for(int i = 0; i < 4; i++){
        if(i < 2) sum_left+=numbers[i];
        else sum_right+=numbers[i];
    }
    if(sum_left == sum_right) cout << "Balanced" << endl;
    else if(sum_left > sum_right) cout << "Left"<< endl;
    else cout << "Right" << endl;
    return 0;
}
