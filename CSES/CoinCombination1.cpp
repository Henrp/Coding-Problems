#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int coin[n];
    for (int i = 0; i < n; i++) cin >> coin[i];

    int64_t mod = 1e9 + 7;
    vector<int64_t> c (x+1, 0);
    c[0] = 1;
    for (int i = 1; i <= x; i++){
        for (auto j : coin){
            if (i - j >= 0){
                (c[i] += c[i-j]) %= mod;
            }
        }
    }

    cout << c[x];
}