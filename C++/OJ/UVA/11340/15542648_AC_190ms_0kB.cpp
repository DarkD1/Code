#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	int T, K, M;
	map <char, double> mp;
	char c;
	string line;
	double v, total;
	scanf("%d", &T);
	while(T--)
	{
		total = 0;
		scanf("%d", &K);
		for(int i = 0; i < K; i++){
			cin >> c >> v;
			mp[c] = v;
		}
		scanf("%d", &M);
		cin.ignore();
		for(int i = 0; i < M; i++){
			getline(cin, line);
			for(int j = 0; j < line.size(); j++) total += mp[line[j]];
		}
		total /= 100.0;
		printf("%.2lf$\n", total);
		mp.clear();
	}
	return 0;
}
