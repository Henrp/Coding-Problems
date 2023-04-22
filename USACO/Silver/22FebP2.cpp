#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

using P = pair<ll, ll>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<P> op;

vector<pair<P, int>> all_subset(int l, int r)
{
    int len = r-l+1;
    vector<pair<P, int>> s;
    for (int i = 0; i < (1 << len); i++){
        ll sumFirst = 0, sumSecond = 0;
        int count = 0;
        for (int j = 0; j < len; j++){
            if (i & (1 << j)){
                sumFirst += op[l+j].first; 
                sumSecond += op[l+j].second;

                count++;
            }
        }
        s.push_back({{sumFirst, sumSecond}, count});
    }
    return s;
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    ll q, w; cin >> q >> w;
    
    op.resize(k);
    for (int i = 0; i < k; i++){
        cin >> op[i].first >> op[i].second;
    }

    vector<pair<P, int>> left = all_subset(0, k/2 - 1);
    vector<pair<P, int>> right = all_subset(k/2, k-1);

    vector<int> ans (k + 1, 0);
    for (auto cur : left){
        
    }

    
    for (size_t i = 1; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}
