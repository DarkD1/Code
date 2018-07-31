/*
    Write a program to find the sum of two numbers declared in a class and display the numbers and sum using friend class;

*/

#include <bits/stdc++.h>
using namespace std;

class First{
    int num1, num2;
public:
    First(){
        num1 = 0;
        num2 = 0;
    }
    void setdata(int n, int m){
        num1 = n;
        num2 = m;
    }
    friend class Second;
};

class Second{
public:
    void showdata(First obj){
        cout << "First value : " << obj.num1 << endl << "Second Value : " << obj.num2 << endl;
    }
    void sum(First obj){
        cout << "Sum is : " << obj.num1 + obj.num2 << endl;
    }
};

int main(){
    First o;
    Second o2;
    int a, b;
    cout << "Enter two value: ";
    cin >> a >> b;
    o.setdata(a, b);
    o2.showdata(o);
    o2.sum(o);
    return 0;
}

