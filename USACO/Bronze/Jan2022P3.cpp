#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solve()
{
    ll ans = 0;
    ll n; cin >> n;

    ll arr[n];
    for (ll i = 0; i < n; i++) cin >> arr[i];

    if (n == 1) return 0;

    for (ll j = 0; j < 2; j++){
        for (ll i = 1; i < n-1; i++){
            if (arr[i-1] < arr[i]){
                ll dif = arr[i] - arr[i-1];
                ans += 2*dif; arr[i] = arr[i-1]; arr[i+1] -= dif;

                if (arr[i+1] < 0) return -1;
            } 
        }

        if (arr[n-1] > arr[n-2]) return -1;
        reverse(arr, arr+n);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;

    while (t--){
        cout << solve() << '\n';
    }
}

