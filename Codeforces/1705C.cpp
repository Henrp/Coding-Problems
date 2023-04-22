#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve()
{
    string str;
    int n, c, q; 
    cin >> n >> c >> q >> str;

    vector<long long> left(c+1), right(c+1), diff(c+1);
    left[0] = 0, right[0] = n;
    for (int i = 1; i <= c; i++){
        long long l, r; cin >> l >> r;
        l--, r--;
        left[i] = right[i-1];
        right[i] = left[i] + (r-l+1);
        diff[i] = left[i] - l;
    }

    while(q--){
        long long queries; cin >> queries; 
        queries--;
        for (int i = c; i >= 1; i--){
            if (left[i] > queries) continue;
            else queries -= diff[i];
        }

        cout << str[queries] << "\n";
    }
}

int main()
{
    int t; cin >> t;
    while(t--){
        solve();
    }
}