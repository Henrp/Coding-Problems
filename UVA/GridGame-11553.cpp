#include <iostream>
#include <vector>
using namespace std;

int n, ans = 10000000;
vector<vector<int>> grid, permutations;
vector<int> temp;
vector<bool> vis;

void perm(int p)
{
    if (p == n){
        permutations.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        temp.push_back(i);
        vis[i] = true;
        perm(p+1);
        vis[i] = false;
        temp.pop_back();
    }
}

void solve()
{
    cin >> n;
    permutations.clear();
    temp.clear();

    perm(0);

    grid.resize(n, vector<int>(n));
    vis.resize(n, false);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    //error most likely here
    for (size_t i = 0; i < permutations.size(); i++){
        int sum = 0; 
        for (size_t j = 0; j < permutations[i].size(); j++){
            sum += grid[i][permutations[i][j]];
        }
        ans = min(ans, sum);
    }

    cout << ans << "\n";
}

int main()
{
    int T; cin >> T;
    while (T--){
        solve();
        ans = 10000000;
    }
}
 