#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<bool> visited;
void dfs(vector<vector<int>> graph, int node)
{
    visited[node] = true;
    for (int i : graph[node]){
        if (!visited[i]) 
            dfs(graph, i);
    }
}

int dist(int x1, int y1, int x2, int y2)
{
    int total = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return total;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<pair<int, int>> coor;
    visited.resize(n, false);
    vector<int> power;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        coor.push_back({a, b});
        power.push_back(c);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist(coor[i].first, coor[i].second, coor[j].first, coor[j].second) <= power[i]*power[i]) graph[i].push_back(j);
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++){
        dfs(graph, i);

        int temp = 0;
        for (int j = 0; j < n; j++){
            if (visited[j]){
                temp++;
            }
        }

        ans = max(ans, temp);
        for (int j = 0; j < n; j++){
            visited[j] = false;
        }
    }

    cout << ans;
}