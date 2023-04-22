#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;

    multiset<int> towers;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        auto it = towers.upper_bound(num);

        if (it == towers.end()){
            towers.insert(num);
        } else {
            towers.erase(it);
            towers.insert(num);
        }
        
    }

    cout << towers.size();
    
}