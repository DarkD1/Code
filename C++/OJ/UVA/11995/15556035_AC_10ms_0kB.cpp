#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, op, x;
	while (scanf("%d", &n) != EOF) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool S = true, Q = true, PQ = true;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &op, &x);

			switch (op) {
			case 1:
				if (S)
					s.push(x);
				if (Q)
					q.push(x);
				if (PQ)
					pq.push(x);
				break;
			case 2:
				if (S) {
					if (s.empty() || s.top() != x)
						S = false;
					else
						s.pop();
				}
				if (Q) {
					if (q.empty() || q.front() != x)
						Q = false;
					else
						q.pop();
				}
				if (PQ) {
					if (pq.empty() || pq.top() != x)
						PQ = false;
					else
						pq.pop();
				}
				break;
			}
		}

		if (S == true && Q == false && PQ == false)
			cout << "stack" << endl;
		else if (S == false && Q == true && PQ == false)
			cout << "queue" << endl;
		else if (S == false && Q == false && PQ == true)
			cout << "priority queue" << endl;
		else if (S == false && Q == false && PQ == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
        return 0;
}
