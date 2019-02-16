#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, currentSize, maxSize = 0, LastidxValue, startingValue;
	map<int, int> m;
	cin >> n;
	vector<int> l(n);
	for(int i= 0; i< n; i++) {
		cin >> l[i];
		m[l[i]] = m[l[i]-1] + 1;
		currentSize = m[l[i]];
		if(currentSize > maxSize) maxSize = currentSize, LastidxValue = l[i];
	}
	cout << maxSize << endl;
	startingValue = LastidxValue - maxSize + 1;
	for(int i=0; maxSize; i++) {
		if(l[i] == startingValue) {
			cout << i+1 << " ";
			maxSize--, startingValue++;
		}
	}
	return 0;
}
/*
7
3 3 4 7 5 6 8

3 currentSize = 1 maxSize = 1, LastidxValue = 3
4 currentSize = 2 maxSize = 2, LastidxValue = 4
7 currentSize = 1 maxSize = 2, LastidxValue = 4
5 currentSize = 3 maxSize = 3, LastidxValue = 5
6 currentSize = 4 maxSize = 4, LastidxValue = 6
8 currentSize = 1 maxSize = 3, LastidxValue = 6
startingValue = 6 - 4 + 1 = 3

*/
