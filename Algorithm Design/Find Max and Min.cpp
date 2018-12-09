#include <iostream>

using namespace std;
int mx, mn, mx1, mn1;
void fMaxMin(int *a, int i, int j, int &m ,int &n){
    if(i == j) m = n = a[i];
    else if(i == j - 1){
        if(a[i] > a[j]) m = a[i], n = a[j];
        else n = a[i], m = a[j];
    }
    else {
        fMaxMin(a, i, (i+j)/2, mx, mn);
        fMaxMin(a,((i+j)/2) + 1, j, mx1, mn1);
        mx = mx1 > mx? mx1 : mx;
        mn = mn1 < mn? mn1 : mn;
    }
}
int main(){
    int n;
    cout << "How many elements you want to insert? : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // searching starts from here
    fMaxMin(arr, 0, n - 1, mx, mn);
    cout << "Max element of the array is: " << mx << endl << "Min element of the array is: " << mn << endl;
    return 0;
}

