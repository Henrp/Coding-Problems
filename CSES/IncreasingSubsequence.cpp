#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    
    vector<int> ar;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        ar.push_back(a);
    }

    vector<int> ans;
    for (int i : ar){
        int pos = lower_bound(ans.begin(), ans.end(), i) - ans.begin();
        if (pos == ans.size()) ans.push_back(i);
        else {
            ans[pos] = i;
        }
    }

    cout << ans.size();


}