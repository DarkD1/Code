#include <bits/stdc++.h>
using namespace std;
#define mx 10000
int arr[mx + 1];
int s;
bool sos(int n, int sum){
    if(sum == 0)
        return true;
    if(n == -1 && sum != 0)
        return false;
    if(arr[n] > sum)
        return sos(n - 1, sum);
    return sos(n - 1, sum) || sos(n - 1, sum - arr[n]);
}
void sos1(int left, int right, int sum = 0){
    if(left > right){
        cout << sum << endl;
        return;
    }
    cout << arr[left] << " ";
    sos1(left + 1, right, sum + arr[left]);
    sos1(left + 1, right, sum);
}
int main(){
    int n, sum;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the sum: ");
    scanf("%d", &sum);
//    init(n, sum);
//    if(sos(n - 1, sum)){
//        cout << "Subset present\n";
//    }
//    else{
//        cout << "Sorry mate\n";
//    }
    sos1(0, n - 1);
    return 0;
}
