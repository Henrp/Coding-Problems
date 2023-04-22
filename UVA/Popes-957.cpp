#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int period;
    while (cin >> period){
        int n; cin >> n;
        vector<int> num(n); 
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }

        int l, r, ans = 0, diff;
        for (int i = 0; i < n; i++){
            int idx = upper_bound(num.begin(), num.end(), num[i] + period-1) - num.begin();
            diff = idx - i;
            if (diff > ans){
                ans = diff;
                l = num[i], r = num[idx-1];
            }
        }
        cout << ans << " " << l << " " << r << "\n";
    }
}