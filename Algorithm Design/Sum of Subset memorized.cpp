#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> lookup;

bool subsetSum(int arr[], int n, int sum){
    if (sum == 0)
		return true;
	if (n < 0 || sum < 0)
		return false;
	string key = to_string(n) + "|" + to_string(sum);
	if (lookup.find(key) == lookup.end()){
		bool include = subsetSum(arr, n - 1, sum - arr[n]);
		bool exclude = subsetSum(arr, n - 1, sum);
		lookup[key] = include || exclude;
	}
	return lookup[key];
}
int main(){
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;
    int n = sizeof(arr) / sizeof(arr[0]);sss
	if (subsetSum(arr, n - 1, sum))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
