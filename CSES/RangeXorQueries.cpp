#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q; cin >> n >> q;
    vector<int> num;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        num.push_back(a);
    }

    for (int i = 1; i < n; i++){
        num[i] ^= num[i-1];
    }
    
    while (q--){
        int a, b; cin >> a >> b; a--, b--;
        if (a-1 < 0 || b-1 < 0) cout << num[b] << "\n";
        else{
            int ans = num[b] ^ num[a-1];
            cout << ans << "\n";
        } 
    }

    
} 