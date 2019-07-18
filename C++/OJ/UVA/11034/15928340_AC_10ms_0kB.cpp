#include <bits/stdc++.h>
using namespace std;

int main(){
    int test_case, l, m;
    cin >> test_case;
    while(test_case--){
        cin >> l >> m;
        queue<int> L, R;
        while(m--){
            int x;
            string y;
            cin >> x >> y;
            y == "right" ? R.push(x) : L.push(x);
        }
        int times = 0;
        bool r = false;
        for(;!L.empty() || !R.empty(); ){
            int load = 0;
            if(r)
                while(!R.empty() && load + R.front() <= l*100)
                    load += R.front(), R.pop();
            else
                while(!L.empty() && load + L.front() <= l*100)
                    load += L.front(), L.pop();
            r = !r;
            times++;
        }
        cout << times << endl;
    }
    return 0;
}
