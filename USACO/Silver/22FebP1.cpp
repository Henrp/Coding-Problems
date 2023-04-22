#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> graph(501), revGraph(501);
vector<bool> vis1(501, false), vis2(501, false);
vector<int> path;

set<int> SCC;

void dfs1(int node)
{
    vis1[node] = true;

    for (int j : graph[node]){
        if (!vis1[j]){
            dfs1(j);
        }
    }

    path.push_back(node);
}

void dfs2(int node)
{
    vis2[node] = true;
    for (int i : revGraph[node]){
        if (!vis2[i]){
            dfs2(i);
        }
    }
    SCC.insert(node);
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        graph[i].resize(n);
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
        while (graph[i].back() != i){
            graph[i].pop_back();
        }
        for (int j : graph[i]){
            revGraph[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++){
        if (!vis1[i]) dfs1(i);
    }

    reverse(path.begin(), path.end());
    
    vector<int> ans (n+1);
    for (int i : path){
        if (!vis2[i]){
            dfs2(i);
            
            for (int j : SCC){
                for (int k : graph[j]){
                    if (SCC.count(k)){
                        ans[j] = k;
                        break;
                    }
                }
            }

            SCC.clear();
        }
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> wish (n, vector<int> (n));
    vector<int> curr(n);
    for (int i = 1; i <= n; i++) curr[i-1] = i;

    vector<int> ind(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> wish[i][j];
            if (wish[i][j] == i+1){
                ind[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (curr[i] == wish[i][0]){
            continue;
        } 

        for (int j = 0; j < ind[i]; j++){
            int found = lower_bound(curr.begin(), curr.end(), wish[i][j]) - curr.begin();
            int comp = lower_bound(wish[found].begin(), wish[found].end(), curr[i]) - wish[found].begin();

            if (comp < ind[found]){
                swap(curr[i], curr[found]);
                ind[i] = j;
                ind[found] = comp;
            }

        }
    }

    for (int i = 0; i < n; i++){
        cout << curr[i] << "\n";
    }
}
*/