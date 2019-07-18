#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int num;
    while (cin >> num, num){
        int a = 0, b = 0;
        bool X = true;
        int add = 1;
        while (num){
            if (num & 1){
                X? a += add : b += add;
                X = !X;
            }
            add <<= 1; // add *= 2
            num >>= 1; // num /= 2
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
