#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> adj[100000], comps[100000];
vector<int> groups (100000, -1);

void dfs(int barn_num, int num)
{
    if (groups[barn_num] != -1) return;
    groups[barn_num] = num;
    for (int i : adj[barn_num]) dfs(i, num);
}

ll cost(int a, int b)
{
    int dist = 100000;
    for (int u : comps[a]){
        int i = lower_bound(comps[b].begin(), comps[b].end(), u) - comps[b].begin();

        if (i > 0) dist = min(dist, abs(comps[b][i-1] - u));
        if (i < comps[b].size()) dist = min(dist, abs(comps[b][i] - u));
    }

    return (ll)dist*dist;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a--].push_back(b--);
        adj[b].push_back(a);
    }

    int comp_num = -1;
    for (int i = 0; i < n; i++){
        if(groups[i] == -1) dfs(i, comp_num++); //if something is wrong change this to ++comp_num
    }

    for (int i = 0; i < n; i++){
        comps[groups[i]].push_back(i);
    }

    ll ans = cost(groups[0], groups[n-1]);
    for (int i = 1; i < comp_num; i++){
        ans = min(ans, cost(i, groups[0]) + cost(i, groups[n-1]));
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        solve();
    }

    return 0;
}
