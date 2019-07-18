/*
    Using the concept of function overloading. Write a c++ program for calculating the area of triangle , circle and rectangle;

*/

#include <bits/stdc++.h>
using namespace std;

void area(int w, int h){
    cout << "Area of Rectangle is : " << w * h << endl;
}
void area(int r){
    cout << "Area of Circle is : " << acos(-1) * r * r << endl;
}
void area(short int b, short int h){
    cout << "Area of Triangle is : " << .5 * b * h << endl;
}
int main(){
    int w, h1, r;
    short int b, h2;
    cout << "Width of Rectangle : " ;
    cin >> w;
    cout << "Height of Rectangle : " ;
    cin >> h1;
    area(w, h1);
    cout << "Radius of Circle : " ;
    cin >> r;
    area(r);
    cout << "Base of Triangle : " ;
    cin >> b;
    cout << "Height of Triangle : " ;
    cin >> h2;
    area(b, h2);
    return 0;
}


