#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int cows[n];
    for (int i = 0; i < n; i++){
        cin >> cows[i];
    }

    int max_ind = max_element(cows, cows+n) - cows;

    if (sizeof(cows)/sizeof(cows[0]) == 1){
        cout << -1 << "\n";
    } else if (sizeof(cows)/sizeof(cows[0]) == 2){
        if (cows[0] == cows[1]){
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else if (sizeof(cows)/sizeof(cows[0]) == 3){
        if (cows[0] != cows[1] && cows[1] != cows[2]){
            if (max_ind != 1){
                cout << -1 << "\n";
                return;
            }
        }

        if (cows[0] == cows[1] && cows[1] == cows[2]){
            cout << 0 << "\n";
            return;
        }
        
        if (cows[0] > cows[1]){

        } else {

        }
    } else {

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        solve();
    }
}