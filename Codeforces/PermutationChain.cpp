#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> num (n);
    for (int i = 1; i <= n; i++) num[i-1] = i;

    cout << n << "\n";
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n; j++) cout << num[j] << " ";
        cout << "\n";
        swap(num[i], num[i+1]);
    }
    for (int j = 0; j < n; j++) cout << num[j] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}