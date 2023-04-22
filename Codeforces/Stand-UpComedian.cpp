#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    int temp = a1;
    int minus = min(a2, a3);
    
    long long ans = a1;
    if (a1 > 0) ans += 2*minus;
    else {
        cout << 1 << "\n";
        return;
    }

    a1 = 0; 
    a2 -= minus, a3 -= minus;

    if (temp < max(a2, a3) + a4){
        ans += (temp+1);
    } else{
        ans += max(a2, a3) + a4;
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(nullptr), ios_base::sync_with_stdio(false);

    int n; cin >> n;
    while (n--){
        solve();
    }
}