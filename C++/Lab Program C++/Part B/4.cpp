#include <bits/stdc++.h>
using namespace std;
class SHAPE{
protected:
    double base, height;
public:
    void getdata(){
        cin >> base;
        cin >> height;
    }
    virtual void display() = 0;
};
class TRIANGLE: public SHAPE{
public:

    virtual void display(){
        cout << "Area of triangle is : " << (.5 *base * height) << endl;
    }
};
class RECTANGLE: public SHAPE{
public:
    virtual void display(){
        cout << "Area of rectangle is : " << (base * height) << endl;
    }
};
int main(){
    SHAPE *Pointer;
    TRIANGLE TR;
    RECTANGLE RE;
    cout << "Enter TRIANGLE data: " << endl;
    TR.getdata();
    cout << "Enter RECTANGLE data: " << endl;
    RE.getdata();
    Pointer = &TR;
    Pointer->display();
    cout << endl;
    Pointer = &RE;
    Pointer->display();
    cout << endl;
    free(Pointer);
    return 0;
}
