#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, c; cin >> n >> c;
    vector<int> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += (i+1);
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (c < a[i]) break;
        c -= a[i];
        ans++;
    }

    cout << ans << "\n";
    return;
}

int main()
{
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    int n; cin >> n;

    while (n--){
        solve();
    }
}