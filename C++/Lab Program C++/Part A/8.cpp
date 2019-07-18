#include <bits/stdc++.h>
using namespace std;
class bank {
    string name = "", type ="", account_number ="";
    float balance = 0.0f;
public:
    void setdata(string n, string t, string acc, float b);
    void deposit(float t);
    void withdraw(float t);
    void showdata();
};
void bank::setdata(string n, string t, string acc, float b){
    name = n;
    type = t;
    account_number = acc;
    balance = b;
}
void bank::deposit(float t){
    balance += t;
}
void bank::withdraw(float t){
    if(balance >= t) balance -= t;
    else cout << "Insufficient Balance" << endl;
}
void bank::showdata(){
    cout << "Account Holder : " << name << endl << "Account Type : " << type << endl << "A/C Number : " << account_number << endl << "Current Balance : " << balance << " Taka" << endl;
}
int main(){
    bank a[10];
    int id, balance;
    string name, type, acc;
    char dummy;
    cout << "A/C ID : (1-10) " ;
    cin >> id;
    id--;
    cout << "Account Holder Name : ";
    cin >> name;
    cout << "Account Type : ";
    cin >> type;
    cout << "A/C Number : ";
    cin >> acc;
    cout << "Initial Balance : ";
    cin >> balance;
    cout << endl;
    a[id].setdata(name, type, acc, balance);
    a[id].showdata();
    return 0;
}
