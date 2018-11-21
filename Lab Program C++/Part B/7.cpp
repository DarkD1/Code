#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream input("i.txt");
    ofstream output("o.txt");
    string content;
    for(int i = 0; input.eof()!= true; i++) {
        char temp = input.get();
        if(isspace(temp)) continue;
        content += temp;
    }
    input.close();
    content.pop_back();
    output << content;
    output.close();
    return 0;
}

