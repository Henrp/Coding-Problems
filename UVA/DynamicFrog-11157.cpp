#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 1;
void solve()
{
    int n, d; cin >> n >> d;
    vector<int> v;
    v.push_back(0), v.push_back(d);
    for (int i = 0; i < n; i++){
        char a, b; int c; cin >> a >> b >> c;
        v.push_back(c);
        
        if (a == 'B') v.push_back(c);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 2; i < v.size(); i+=2){
        ans = max(ans, v[i] - v[i-2]);
    }
    for (int i = 3; i < v.size(); i+=2){
        ans = max(ans, v[i] - v[i-2]);
    }

    cout << "Case " << num++ << ": " << ans << "\n";
}

int main()
{
    int T; cin >> T;
    while (T--) solve();
}