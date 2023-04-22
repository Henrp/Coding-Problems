#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<bool> visited;
vector<bool> closed;
vector<vector<int>> graph;

int n, m, count = 0;

void dfs(int node)
{
    if (visited[node] || closed[node]) return;

    count++;
    visited[node] = true;
    for (int i : graph[node]){
        if (!visited[i]){
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    cin >> n >> m;

    graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }

    visited.resize(n+1, false);
    closed.resize(n+1, false);

    dfs(1);
    string ans = count == n ? "YES" : "NO";
    cout << ans << "\n";

    vector<int> perm (n);
    for (int i = 0; i < n; i++) cin >> perm[i];

    for (int i = 1; i < n; i++){
        count = 0;
        closed[perm[i-1]] = true;
        fill (visited.begin(), visited.end(), false);

        dfs(perm[n-1]);
        ans = count == n-i ? "YES" : "NO";
        cout << ans << "\n";
    }
}