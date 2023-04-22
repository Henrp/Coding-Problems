#include <iostream>
#include <vector>
#include <queue>  
using namespace std;

vector<int> topo_sort, edges[100001], backEdges[100001], inDegree(100001, 0);

int main()
{
    int n, m; cin >> n >> m;

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

    vector<int> dp (n+1, 0);
    dp[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (int i : edges[node]){
            inDegree[i]--;
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        for (int i : backEdges[node]){
            dp[node] = (dp[node]+dp[i])%1000000007;
        }
    }

    cout << dp[n];
}