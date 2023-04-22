#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph (n+1);
    while (m--){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist (n+1, -1), parent(n+1);
    queue<int> route;
    route.push(1);
    dist[1] = 0;

    while (!route.empty()){
        int parent_node = route.front();
        route.pop();

        for (auto child : graph[parent_node]){
            if (dist[child] == -1){
                route.push(child);
                dist[child] = dist[parent_node] + 1;
                parent[child] = parent_node;
            }
        }
    }

    if (dist[n]== -1) cout << "IMPOSSIBLE";
    else {
        cout << dist[n] + 1 << "\n";   

        vector<int> ans;
        ans.push_back(n);
        while (ans.back() != 1) ans.push_back(parent[ans.back()]);
        reverse(ans.begin(), ans.end());
        for (auto i : ans) cout << i << " ";
    }
}