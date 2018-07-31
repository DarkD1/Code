/*
    Create a class TIME with members hours, minutes, seconds. Take input, add two time objects passing objects to function and display result;
*/

#include <bits/stdc++.h>
using namespace std;

class TIME{
    int hours, minutes, seconds;
public:
    void setdata(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
    }
    void addtime(TIME y){
        int s = (seconds + y.seconds) % 60;
        int m = ((seconds + y.seconds) / 60) + (minutes + y.minutes) % 60;
        int h = ((minutes + y.minutes) / 60) + hours + y.hours;
        cout << h << " hour " << m << " minute " << s << " second"<< endl;
    }
};

int main(){
    TIME ff, ss;
    int h, m, s;
    cout << "Time (h,m,s) : ";
    cin >> h >> m >> s;
    ff.setdata(h, m, s);
    cout << "Time (h,m,s) : ";
    cin >> h >> m >> s;
    ss.setdata(h, m, s);
    ff.addtime(ss);
    return 0;
}
