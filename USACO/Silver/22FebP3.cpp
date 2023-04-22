#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


void solve()
{
    int m, n, lim; cin >> m >> n >> lim;

    string mailnum = "", filenum = "";
    vector<int> freq(m+1, 0);

    for (int i = 1; i <= m; i++) mailnum += to_string(i);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        filenum += to_string(a);
        freq[a]++;
    }

    for (int i = 0; i <= m - lim; i++){
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
        solve();
    }

}
