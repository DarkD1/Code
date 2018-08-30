#include <bits/stdc++.h>

using namespace std;

class String{
    char *str;
    int len = 0;
public:
    void setdata(char *str){
        len = strlen(str);
        this->str = new char[len + 1];
        strcpy(this->str, str);
    }
    void display(){
        cout << this->str << endl;
    }
    String operator+ (String obj){
        String temp;
        temp.len = this->len + obj.len;
        temp.str = new char [temp.len + 1];
        strcpy(temp.str, this->str);
        strcat(temp.str, obj.str);
        return temp;
    }
    String operator= (String obj){
        len = obj.len + 1;
        str = new char [len];
        strcpy(str, obj.str);
        return *this;
    }
};

int main(){
    String object1, object2, object3, object4;
    char str[] = "Sazzad ", str2[] = "Hossain";
    object1.setdata(str);
    object2.setdata(str2);
    object3 = object1 + object2;
    object3.display();
    object4 = object3;
    object4.display();
    return 0;
}
