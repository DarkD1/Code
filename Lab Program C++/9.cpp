/*
    Create two classes DM and DB which store the value of distances: DM in meter, centimeter and DB in feet, inches.
    -Write a program that can read values for the class objects.
    -Add one object of DM with another object of DM using friend function.
    -Display all the objects in appropriate units.
*/
#include <bits/stdc++.h>
using namespace std;
class DB;
class DM{
    int meter, centimeter;
public:
    void getdata(){
        cout << "Enter meter : ";
        cin >> meter;
        cout << "Enter centimeter : ";
        cin >> centimeter;
        meter += centimeter / 100;
        centimeter %= 100;
    }
    void showdata(){
        cout << meter << " meter and " << centimeter << " centimeters" << endl;
    }
    friend void add(DM x, DB y);
};

class DB{
    int feet, inch;
public:
    void getdata(){
        cout << "Enter feet : ";
        cin >> feet;
        cout << "Enter inch : ";
        cin >> inch;
        feet += inch / 12;
        inch %= 12;
    }
    void showdata(){
        cout << feet << " feet and " << inch << " inches" << endl;
    }
    friend void add(DM x, DB y);
};
void add(DM x, DB y){
    float DM_meter, DB_feet, DM_centi, DB_inch;
    DM_centi = x.centimeter + (y.inch * 2.54);
    DM_meter = (DM_centi / 100) + x.meter + (y.feet * 0.3048);
    DM_centi = DM_centi - (100 * (DM_centi / 100));
    DB_inch = y.inch + (x.centimeter * 0.393701);
    DB_feet = (DB_inch / 12) + y.feet + (x.meter * 3.28);
    DB_inch = DB_inch - (12 * (DB_inch / 12));
    cout << "Result is : " << endl << DM_meter << " meter and " << DM_centi << " centimeters" << endl;
    cout << DB_feet << " feet and " << DB_inch << " inches" << endl;
}
int main(){
    DB b;
    DM a;
    a.getdata();
    cout << endl;
    b.getdata();
    cout << endl;
    a.showdata();
    cout << endl;
    b.showdata();
    cout << endl;
    add(a, b);
    return 0;
}
