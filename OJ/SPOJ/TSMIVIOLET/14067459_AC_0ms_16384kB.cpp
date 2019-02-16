#include <iostream>
#include <string>
using namespace std;

int main(){
    string x;
    getline(cin , x);
    if(x == "Saturday") cout << "Sandwich\n";
    else if(x == "Sunday") cout << "Soup\n";
    else if(x == "Monday") cout << "Macaroon\n";
    else if(x == "Tuesday") cout << "Toffee\n";
    else if(x == "Wednesday") cout << "Waffles\n";
    else if(x == "Thursday") cout << "Taco\n";
    else if(x == "Friday") cout << "French Fries\n";
    return 0;
}

