/*
    Write a program to find the greater of two given numbers in two different classes using friend function;
*/

#include <bits/stdc++.h>
using namespace std;
class Second;
class First{
    int num;
public:
    First(){
        num = 0;
    }
    void setdata(int n){
        num = n;
    }
    friend void compare(First obj, Second obj2);
};
class Second{
    int num;
public:
    Second(){
        num = 0;
    }
    void setdata(int n){
        num = n;
    }
    friend void compare(First obj, Second obj2);
};
void compare(First obj, Second obj2){
    cout << "Greater number is : " << max(obj.num, obj2.num) << endl;
}
int main(){
    First o;
    Second o2;
    int a, b;
    cout << "Data for First Class : ";
    cin >> a;
    cout << "Data for Second Class : ";
    cin >> b;
    o.setdata(a);
    o2.setdata(b);
    compare(o, o2);
    return 0;
}
