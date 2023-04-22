#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long ar[n];
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; i++){
        if (ar[i-1] > ar[i]){
            ans += (ar[i-1]-ar[i]);
            ar[i] += (ar[i-1]-ar[i]);
        }
    }

    cout << ans;
}