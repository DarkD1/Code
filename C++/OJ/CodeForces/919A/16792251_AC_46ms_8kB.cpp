#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
int main(){
	int n, m;
    double minimum;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(i == 0) minimum = (a* 1.0 / b)  * m;
		else {
            minimum = min(((a * 1.0/ b)* m), minimum);
		}
    }
    printf("%.8f", minimum);
	return 0;
}



