/*
    Create a class Student which has data members as name, semester, roll no, section, marks in five subjects. Display all information of the student who has more than 40% marks. Use array of objects;
*/

#include <bits/stdc++.h>
using namespace std;

class Student{
    string name;
    char sec;
    int sem, roll;
    vector<int> marks;
    float percentage;
public:
    void setdata(string n, char s, int se, int r, vector<int> m){
        name = n;
        sec = s;
        sem = se;
        roll = r;
        marks = m;
    }
    void showdata(){
        int total = accumulate(marks.begin(), marks.end(), 0);
        percentage = total * 1.0 / 5;
        if(percentage >= 40) showall();
    }
    void showall(){
        cout << "Name : " << name << endl << "Section : " << sec << endl << "Semester : " << sem << endl << "Roll : " << roll << endl << "Percentage : " << percentage << endl << "Marks : ";
        for(auto i: marks) cout << i << " ";
        cout << endl;
    }
};

int main(){
    Student obj[10];
    vector<int> m = {40,41,40,45,50};
    obj[0].setdata("Sazzad", 'B', 3, 17081, m);
    obj[0].showdata();
    cout << endl << endl << endl;
    vector<int> n = {45,41,75,62,50};
    obj[1].setdata("Ahadul", 'B', 3, 17099, n);
    obj[1].showdata();
    return 0;
}

