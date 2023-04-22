#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;

int node_num(int n)
{
    return nodes[n] < 0 ? n : nodes[n] = node_num(nodes[n]);
}

int node_size(int n)
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
    int n, q; cin >> n >> q;
    
}