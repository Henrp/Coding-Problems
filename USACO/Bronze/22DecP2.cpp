#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n, k, len = 0; cin >> n >> k;
    if (k != 0) len = k*2+1;

    string cows, ans = ""; cin >> cows;
    for (int i = 0; i < n; i++) ans += ".";

    if (n == 1){
        cout << 1 << "\n";
        cout << cows << "\n";
    }

    vector<bool> guern(n, false), holst(n, false);

    for (int i = 0; i < n; i++){
        if (cows[i] == 'G'){
            guern[i] = true;
        } else if (cows[i] == 'H'){
            holst[i] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        if (guern[i]){
            if (i+k < n) ans[i+k] = 'G';
            else {
                for (int j = n-1; j >= 0 && j >= n-k-1; j--){
                    if (ans[j] == '.'){
                        ans[j] = 'G';
                        break;
                    }
                }
            }
            count++;
            for (int j = 0; i+j < n && j < len; j++){
                guern[i+j] = false;
            }
        }
    }
    //cout << count << "\n";

    for (int i = 0; i < n; i++){
        if (holst[i]){
            if (i+k < n) ans[i+k] = 'H';
            else {
                for (int j = n-1; j >= 0 && j >= n-k-1; j--){
                    if (ans[j] == '.'){
                        ans[j] = 'H';
                        break;
                    }
                }
            }
            count++;
            for (int j = 0; i+j < n && j < len; j++){
                holst[i+j] = false;
            }
        }
    }

    cout << count << "\n";
    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}