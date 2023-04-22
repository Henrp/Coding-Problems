#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;

int node_num(int n)
{
    return nodes[n] < 0 ? n : nodes[n] = node_num(nodes[n]);
}

int size(int n)
{
    return -nodes[node_num(n)];
}

bool unite(int n1, int n2)
{
    n1 = node_num(n1), n2 = node_num(n2);
    if (n1 == n2) return false;
    if (n1 > n2) swap(n1, n2);
    nodes[n1] += nodes[n2]; nodes[n2] = n1;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    int n, q; cin >> n >> q;
    nodes.resize(n, -1);

    vector<int> edge[n];
    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b; a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> cquery;
    for (int i = 0; i < n; i++){
        int a; cin >> a; a--;
        cquery.push_back(a);
    }
    reverse(cquery.begin(), cquery.end());

    vector<string> ans;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        visited[cquery[i]] = true;
        for (int j : edge[cquery[i]]){
            if (visited[j]) unite(cquery[i], j);
        }

        if (i+1 == size(cquery[i])) ans.push_back("YES");
        else ans.push_back("NO");
    }
    
    reverse(ans.begin(), ans.end());

    for (string i : ans) cout << i << "\n";
}