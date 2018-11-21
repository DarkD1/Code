#include<bits/stdc++.h>
using namespace std;
class student{
    string name, sex, age, height, weight;
public:
    void read(){
        cout << "Student name: ";
        getline(cin, name);
        cout << "Gender: ";
        cin >> sex;
        cout << "Student age: ";
        cin >> age;
        cout << "Student height: ";
        cin >> height;
        cout << "Student weight: ";
        cin >> weight;
    }
    void write(){
        ofstream output("o.txt");
        output << "Student name: ";
        output << name << endl;
        output << "Gender: ";
        output << sex << endl;
        output << "Student age: ";
        output << age << endl;
        output << "Student height: ";
        output << height << endl;
        output << "Student weight: ";
        output << weight << endl;
        output.close();
    }
    void show(){
        ifstream showfile("o.txt");
        string content;
        while(getline(showfile, content)) cout << content << endl;
        showfile.close();
    }
};
int main(){
    student obj;
    obj.read();
    obj.write();
    obj.show();
    return 0;
}

