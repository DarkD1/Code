/*
    Write a function power to raise a number m to power n. The function takes a double value for m and int value for n. Use default value for n to make the function to calculate squares when this argument is omitted;

*/

#include <bits/stdc++.h>
using namespace std;

void power_raise(double m, int n = 2){
    cout << "Result is : " << pow(m, n) << endl;;
}

int main(){
    double m;
    int n;
    cin >> m >> n;
    power_raise(m , n);
    cout << "Without the value of n : " ;
    power_raise(m);
    return 0;
}


