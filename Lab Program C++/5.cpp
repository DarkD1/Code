/*
    Write a program to perform addition of two complex numbers using constructor overloading. THe first constructor which takes no argument is used to create objects which are not initialized, second which takes one argument is used to initialize real and imag parts to equal values and third which takes two argument is used to initialized real and imag to two different values;

*/

#include <bits/stdc++.h>
using namespace std;

class complex_n{

float real ,imag;
public:
    complex_n(){
        real = 0;
        imag = 0;
    }
    complex_n(float n){
        real = n;
        imag = n;
    }
    complex_n(float m, float n){
        real = m;
        imag = n;
    }
    void show(){
        cout << "Real part : " << real << endl << "Imaginary part : " << imag << endl;
    }
    void add(complex_n a, complex_n b){
        real = a.real + b.real;
        imag = a.imag + b.imag;
        cout << "Result is : ";
        imag >=0? cout << real <<  " + " << imag << "i": cout << real << " " << imag << "i";
        cout << endl;
    }
};

int main(){
    complex_n x, y(5.0f), z(7.5f, 9.14f), res;
    res.add(y, z);
    return 0;
}
