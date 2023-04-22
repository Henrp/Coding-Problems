#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int n; cin >> n;

    vector<int> adj[n+1];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;

    vector<bool> vis(n+1, false);
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int curNode = q.front();
        vis[curNode] = true;
        q.pop();
        
        int siz = adj[curNode].size();
        if (curNode != 1){
            siz--;
        }

        int val = 1;
        while (val <= siz){
            val*=2;
            ans++;
        }

        for (int nextNode : adj[curNode]){
            if (!vis[nextNode]){
                q.push(nextNode);
                ans++;
            }
        }
    }

    cout << ans;
}