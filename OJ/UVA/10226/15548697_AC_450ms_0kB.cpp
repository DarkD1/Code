#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string x;
    scanf("%d", &t);
    cin.ignore();
    cin.ignore();
    while(t--){
        map <string , int> mp;
        int c = 0;
        while(getline(cin, x)){
            if(x.size() == 0) break;
            mp[x]++;
            c++;
        }
        map<string, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++) {
			printf("%s %.4f\n", (*it).first.data(),(float) (*it).second / (float) c * 100.0);
		}
        if (t > 0)  printf("\n");
    }
    return 0;
}
