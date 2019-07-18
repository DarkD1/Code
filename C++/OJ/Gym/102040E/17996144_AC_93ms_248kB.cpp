#include <bits/stdc++.h>
using namespace std;
vector<string > split(string str){
    vector<string > res;
    string temp;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ':'){
            res.push_back(temp);
            temp = "";
        }
        else temp += str[i];
    }
    res.push_back(temp);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("out.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int n;
    while(cin >> n){
        if(n == 0) break;
        cin.ignore();
        int totalLate = 0, totalFail = 0;
        int pointDeducted = 0;
        for(int i = 1; i <= n; i++){
            string str, shift;
            int startHour, startMin, startSecond;
            int endHour, endMin, endSecond;
            int start, finish, officeTimeD = 8 * 3600 + 30 * 60, officeTimeE = 12 * 3600 + 30 * 60;
            int DTime = 8 * 3600, ETime = 9 * 3600;
            int fail = 0, late = 0;
            getline(cin, str);
    //        scanf("%c:%d:%d:%d:%d:%d:%d", shift, &startHour, &startMin, &startSecond, &endHour, &endMin, &endSecond);
            vector<string > sp = split(str);
            shift = sp[0];
            startHour = stoi(sp[1]) * 3600, startMin = stoi(sp[2]) * 60, startSecond = stoi(sp[3]);
            endHour = stoi(sp[4]) * 3600, endMin = stoi(sp[5]) * 60, endSecond = stoi(sp[6]);
            start = startHour + startMin + startSecond;
            finish = endHour + endMin + endSecond;

            if(shift == "D"){
                if(start < officeTimeD){
                    start = officeTimeD;
                }
                int hoursWorked = finish - start;
                if(hoursWorked < DTime) fail++;
                if(start > officeTimeD + 3600) late++;
                if(fail == 1 && late == 1) pointDeducted++;
                else if(fail == 1) pointDeducted++;
                else if(late == 1) pointDeducted++;
            }
            else{
                if(start < officeTimeD){
                    start = officeTimeD;
                }
                int hoursWorked = finish - start;
                if(hoursWorked < ETime) fail++;
                if(start > officeTimeE) late++;
                if(fail == 1 && late == 1) pointDeducted++;
                else if(fail == 1) pointDeducted++;
                else if(late == 1) pointDeducted++;
            }
        }
        if(pointDeducted > 3){
            cout << "Issue Show Cause Letter" << endl;
        }
        else if(pointDeducted == 3){
            cout << "3 Point(s) Deducted" << endl;
        }
        else if(pointDeducted == 2){
            cout << "2 Point(s) Deducted" << endl;
        }
        else if(pointDeducted == 1){
            cout << "1 Point(s) Deducted" << endl;
        }
        else {
            cout << "All OK" << endl;
        }
    }
    return 0;
}
