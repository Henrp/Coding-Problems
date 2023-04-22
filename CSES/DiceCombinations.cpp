#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    int num[6] = {1, 2, 3, 4, 5, 6};
    vector<int> count(n+1, 0);
    count[0] = 1;
    for (int i = 1; i <= n; i++){
        for (auto j : num){
            if (i-j >= 0){
                (count[i] += count[i-j]) %= mod;
            }
        }
    }

    cout << count[n];
}