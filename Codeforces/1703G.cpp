#include <iostream>
#include <vector>
using namespace std;


void solve()
{
    int n, k; cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> pre (n);
    pre[0] = coins[0]-k;
    for (int i = 1; i < n; i++){
        pre[i] = pre[i-1] + (coins[i]-k);
    }
    
    long long ans = pre[n-1];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
}