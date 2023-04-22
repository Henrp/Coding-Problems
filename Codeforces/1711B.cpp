#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve()
{
    int n, m, ans = 1000000; cin >> n >> m;
    vector<int> deg (n, 0), val(n);

    for (int i = 0; i < n; i++) cin >> val[i];

    vector<pair<int, int>> friends(m);
    for (int i = 0; i < m; i++){
        cin >> friends[i].first >> friends[i].second; 
        friends[i].first--, friends[i].second--;
        deg[friends[i].first]++, deg[friends[i].second]++;
    } 

    if (m%2 == 0) ans = 0;

    for (int i = 0; i < n; i++){
        if (deg[i]%2 == 1){
            ans = min(ans, val[i]);
        }
    }

    for (int i = 0; i < m; i++){
        if (deg[friends[i].first]%2 == 0 && deg[friends[i].second]%2 == 0){
            ans = min(ans, val[friends[i].first] + val[friends[i].second]);
        }
    }

    cout << ans << "\n";
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