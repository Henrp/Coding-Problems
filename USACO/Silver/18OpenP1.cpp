#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("sort.in","r",stdin); 
    freopen("sort.out","w",stdout); 
    int n; cin >> n;

    vector<pair<int, int>> A(n);

    for (int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++){
        A[i].first = i;
    }

    int moo = 0;
    for (int i = 0; i < n; i++){
        moo = max(moo, A[i].second - A[i].first + 1);
    }

    cout << moo;
}