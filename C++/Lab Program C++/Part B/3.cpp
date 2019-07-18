#include <bits/stdc++.h>
using namespace std;
class STUDENT{
protected:
    string name;
    int roll;
public:
    void get_data(){
        cout << "Student name : ";
        getline(cin, name);
        cout << "Student roll : ";
        cin >> roll;
    }
};
class EXAM : public STUDENT{
protected:
    int marks[6];
public:
    void get_mark(){
        cout << "Enter 6 Subject Marks : ";
        for(int i = 0; i < 6; i++) cin >> marks[i];
    }
};
class RESULT : public EXAM{
protected:
    int total = 0;
public:
    void addtotal(){
        for(int i = 0 ; i < 6; i++) total += marks[i];
    }
    void showdata(){
        cout << "Name : " << name << endl;
        cout << "Roll : " << roll << endl;
        cout << "6 Subject marks respectively : ";
        for(int i = 0; i < 6; i++) cout << marks[i] << " ";
        addtotal();
        cout << endl << "Total marks : " << total << endl;
    }
};

int main(){
    RESULT OBJ;
    OBJ.get_data();
    OBJ.get_mark();
    cout << endl << endl;
    OBJ.showdata();
    return 0;
}
