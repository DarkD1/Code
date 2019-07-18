#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[4];
    vector <int> numbers;
    int n = 3;
    while(n--){
        cin >> n;
        numbers.push_back(n);
    }
    scanf("%s", str);
    sort(numbers.begin(), numbers.end());
    numbers.erase(numbers.begin(), numbers.begin()+1);
    for(int i = 0; i < 3; i++){
        if(str[i] == 'C') {
            if(i < 2) cout << numbers[2] << " ";
            else cout << numbers[2];
        }
        else if(str[i] == 'A') {
            if(i < 2) cout << numbers[0] << " ";
            else cout << numbers[0];
        }
        else {
            if(i < 2) cout << numbers[1] << " ";
            else cout << numbers[1];
        }
    }
    return 0;
}
