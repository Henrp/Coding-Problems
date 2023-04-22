#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<pair<ll, ll>> ar;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ar.push_back({a,b});
    }

    sort(ar.begin(), ar.end());

    ll ans = 0, curr_time = 0;
    for (int i = 0; i < n; i++){
        curr_time += ar[i].first;
        ans += (ar[i].second - curr_time);
    }

    cout << ans << "\n";
}