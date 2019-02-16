#include<bits/stdc++.h>
using namespace std;
map<string, int> mp = {{"January", 1},
                        {"February", 2},
                        {"March", 3},
                        {"April", 4},
                        {"May", 5},
                        {"June", 6},
                        {"July", 7},
                        {"August", 8},
                        {"September", 9},
                        {"October", 10},
                        {"November", 11},
                        {"December", 12}};

int leapBefore(int year){
    return (year / 4) - (year / 100) + (year / 400);
}

int main(){
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){

        string sMonth, sDate, sYear, eMonth, eDate, eYear;
        cin >> sMonth >> sDate >> sYear >> eMonth >> eDate >> eYear;
        sDate.pop_back(), eDate.pop_back();

        int s = stoi(sYear), e = stoi(eYear);
        if(mp[sMonth] > 2) s++;
        if(mp[eMonth] == 1 || (mp[eMonth] == 2 && stoi(eDate) < 29)) e--;
        int noOfLeapYear = leapBefore(e) - leapBefore(s - 1);

        printf("Case %d: %d\n", i, noOfLeapYear);
    }
    return 0;
}
