#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//BFS
const int MAX = 100001;
int main()
{
    vector<int> graph [MAX], indegree(MAX, 0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++){
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo_sort;
    while (!q.empty()){
        int curr = q.front(); q.pop();
        topo_sort.push_back(curr);

        for (int num : graph[curr]){
            indegree[num]--;
            if (indegree[num] == 0){
                q.push(num);
            }
        }
    }

    if (topo_sort.size() != n) 
        cout << "IMPOSSIBLE";
        exit(0);

    
    for  (int i : topo_sort) cout << i << " ";

}
//DFS 
/*
const int MAX = 100001;
vector<int> graph [MAX], cyc_nodes;
bool visited[MAX], on_stack[MAX];

bool dfs(int node)
{
    visited[node] = on_stack[node] = true;
    for (int u : graph[node]){
        if (on_stack[u]){
            cyc_nodes.push_back(node);
            on_stack[u] = on_stack[node] = false;
            return true;
        } else if (!visited[u]){
            if (dfs(u)){
                if (on_stack[node]){
                    cyc_nodes.push_back(node);
                    on_stack[node] = false;
                    return true;
                } else {
                    cyc_nodes.push_back(node);
                    return false;
                }
            } 

            if (!cyc_nodes.empty()) return false;
        }
    }
    on_stack[node] = false;
    return false;
}

int main()
{
    int n, m; cin >> n >> m; 
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    for (int i = 0; cyc_nodes.empty() && i < n; i++) dfs(i);

    if (cyc_nodes.empty()){
        cout << "IMPOSSIBLE"; exit(0);
    } else {
        reverse(cyc_nodes.begin(), cyc_nodes.end());
        cout << cyc_nodes.size()+1 << "\n" << cyc_nodes[cyc_nodes.size()-1]+1 << " ";
        for (int i : cyc_nodes) cout << i+1 << " ";
    }
}
*/