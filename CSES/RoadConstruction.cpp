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

bool unite(int a, int b)
{
    a = node_num(a), b = node_num(b);
    if (a == b) return false;
    if (nodes[a] > nodes[b]) swap(a, b);
    nodes[a] += nodes[b]; nodes[b] = a; 
    return true;
    
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;
    nodes.resize(n, -1);

    int nc = n, lc = 1;
    for (int i = 0; i < q; i++){
        int u, v; cin >> u >> v; u--, v--;
        if (unite(u, v)){
            lc = max(lc, size(u));
            nc--;
        }

        cout << nc << " " << lc << "\n";
    }
}