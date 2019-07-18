#include <bits/stdc++.h>
using namespace std;

int main() {
    int stop, in = 0, out = 0, exit = 0, counting = 0, capacity = 0, temp = 0;
    cin >> stop;
    cin >> in >> out;
    counting = in + out;
    capacity = counting;
    for(int i = 0; i < stop-1; i++){
        cin >> in;
        cin >> out;
        counting -= in;
        counting += out;
        if(counting > capacity) capacity = counting;
    }
    cout << capacity << endl;
    return 0;
}
