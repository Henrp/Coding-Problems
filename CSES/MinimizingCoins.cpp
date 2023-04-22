#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int INF = 10e6+1;
    vector<int> val(x+1);
    val[0] = 0;
    for (int i = 1; i <= x; i++){
        val[i] = INF;
        for (auto j : coins){   
            if (i-j >= 0) {
                val[i] = min(val[i], val[i-j] + 1);
            }
        }
    }

    cout << int((val[x] == INF) ? -1 : val[x]);
}