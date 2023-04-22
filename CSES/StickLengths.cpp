#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    ll ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    sort(ar, ar+n);

    ll m = ar[n/2], cost = 0;
    for (int i = 0; i < n; i++){
        cost += abs(m-ar[i]);
    }

    cout << cost;
}