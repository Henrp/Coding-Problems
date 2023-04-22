#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;

        int total = 0;
        bool same = true;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            total += arr[i];
        }

        for (int i = 0; i < n; i++){
            if (arr[i] != arr[0]) same = false;
        }
        
        if (same){
            cout << 0 << "\n";
        } else {
            bool found = false;
            for (int i = total-1; i > 1; i--){
                if (total % i != 0) continue;

                int factor = total/i, tempsum = 0, numop = 0;
                for (int j = 0; j < n; j++){
                    if (arr[j] != factor && tempsum > 0) numop++;
                    tempsum += arr[j];
                    if (tempsum > factor){
                        break;
                    } else if (tempsum == factor){
                        tempsum = 0;
                    }

                    if (j == n-1){
                        cout << numop << "\n";
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) cout << n-1 << "\n";
        }
    }
}