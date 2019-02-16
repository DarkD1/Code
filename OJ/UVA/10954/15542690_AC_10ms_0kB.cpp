#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
	while (cin >> n) {
        if(n == 0) return 0;
		priority_queue<int, vector<int>, greater<int> > p;
		int total = 0, cost = 0;
		while (n--) {
			int x;
			cin >> x;
			p.push(x);
		}
		while (p.size() > 1) {
			total = p.top();
			p.pop();
			total += p.top();
			p.pop();
			cost += total;
			p.push(total);
		}
		cout << cost << endl;
	}
	return 0;
}
