#include <bits/stdc++.h>
using namespace std;

bool prime(int a){
    for(int i = 2; i <= sqrt(a); i++) if(a % i == 0) return 0;
    return 1;
}

bool not_prime(vector <int> a){
    for(int i = 0; i < a.size(); i++){
        if(prime(a[i])) return 1;
    }
    return 0;
}
int main(){
    int n;
    vector <string> names;
    vector <vector <int> > numbers;

    vector <int> add;
    cin >> n;
    string dummy;
    for(int i=0; i < n; i++){
        char name[20];
        int x;
        scanf("%s",name);
        cin >> x;

        names.push_back(name);
        add.push_back(x);
    }
    for(int i = 0; i < n; i++){
        vector <int> xx;
        for(int j = 0; j < names[i].size(); j++){
            int sum = 0;
            sum = int(names[i][j]) + add[i];
            xx.push_back(sum);
        }
        numbers.push_back(xx);
    }
    for(int i = 0; i < n; i++)
    (not_prime(numbers[i]))? cout << "YES\n" : cout << "NO\n";
    return 0;
}
