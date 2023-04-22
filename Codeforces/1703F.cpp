#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> element(n); 
    for (int i = 0; i < n; i++){
        cin >> element[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++){
        if (element[i] < i+1){
            for (int j = i+1; j < n; j++){
                if (i+1 < element[j] && element[j] < j+1) ans++;
            }
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