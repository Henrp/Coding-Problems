#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> edges[n+1], backEdges[n+1], inDegree (n+1, 0);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        backEdges[b].push_back(a);
        inDegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> numRoutes (n+1, 0), routeNodes(n+1, 0);
    numRoutes[1] = 1;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (int i : edges[node]){
            inDegree[i]--;
            if (inDegree[i] == 0) q.push(i);
        }

        for (int i : backEdges[node]){
            if (numRoutes[node] < numRoutes[i]+1){
                numRoutes[node] = numRoutes[i]+1;
                routeNodes[node] = i;
            }
        }
    }

    cout << numRoutes[n] << "\n";
    stack<int> ans;
    int node = n;

    node = routeNodes[node-1];
    //cout << node;
    for (int i : routeNodes) cout << i << " ";

}