#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long group[20];
long long apple(int ind, long long s1, long long s2)
{
    if (ind == n){
        return abs(s1-s2);
    }

    return min(apple(ind+1, s1+group[ind], s2), apple(ind+1, s1, s2+group[ind]));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> group[i];
    }

    cout << apple(0, 0, 0);
}