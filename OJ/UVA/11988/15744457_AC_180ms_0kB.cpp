#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string str;
    list<char> maintext;
    list<char>::iterator it;
    while(getline(cin,str))
    {
        maintext.clear();
        it = maintext.begin();
        for(char i: str){
            if(i =='[')	it = maintext.begin();
            if(i ==']')	it = maintext.end();
            if(i != '[' && i !=']')	maintext.insert(it,i);
        }
        for(it = maintext.begin(); it != maintext.end(); it++)	cout << *it ;
        printf("\n");
    }
    return 0;
}