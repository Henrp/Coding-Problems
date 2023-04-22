#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

long long n, total = 0, ave;
vector<long long> bale_num, subtree;
vector<vector<int>> adj;

vector<tuple<int, int, long long>> ans;

void build_subtree(int node = 0, int parent = 0)
{
    subtree[node] = bale_num[node] - ave;
    for (int child : adj[node]){
        if (child != parent){
            build_subtree(child, node);
            subtree[node] += subtree[child];
        }
    }
}

void DFS(int node = 0, int parent = 0)
{
    for (int next : adj[node]){
        if (next != parent){
            if (subtree[next] >= 0) DFS(next, node);
            if (subtree[next] > 0){
                ans.emplace_back(next, node, subtree[next]);
            }
        }
    }

    for (int next : adj[node]){
        if (next != parent && subtree[next] < 0){
            ans.emplace_back(node, next, -subtree[next]);
            DFS(next, node);
        }
    }
}

int main()
{
    cin >> n;
    bale_num.resize(n), adj.resize(n), subtree.resize(n);

    for (int i = 0; i < n; i++){
        cin >> bale_num[i];
        total+=bale_num[i];
    }
    ave = total/n; //might be error here 

    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    build_subtree();    
    DFS();

    cout << ans.size() << "\n";
    for (auto [a, b, c] : ans){
        cout << ++a << " " << ++b << " " << c << "\n";
    }
}