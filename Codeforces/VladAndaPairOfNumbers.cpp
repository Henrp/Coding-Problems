#include <iostream>
#include <bitset>
using namespace std;

void solve()
{
    int x; cin >> x;

    int a = x, b = 0;
    for (int i = 32; i >= 0; i--){
        if (x & (1 << i) > 0){
            continue;
        }

        if ()
    }

    return;
}

int main()
{
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    int t; cin >> t;

    while (t--){
        solve();
    }
}