#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    set<int> num;
    vector<int> freq (1000001, 0);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        freq[a]++;
        num.insert(a);
    }

    //for (int i : num) cout << i << " ";
    long long number = n, ans = 0, count;
    for (int i : num){
        if (i*number > ans){
            ans = i*number;
            count = i;
        }
        number -= freq[i];
    }

    cout << ans << " " << count;
}