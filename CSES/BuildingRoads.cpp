#include <iostream>
#include <vector>
using namespace std;

const int size = 1e5 + 10;
vector<int> ar[size];
bool yesno[size];

void dfs(int node)
{
    yesno[node] = true;
    for (int i : ar[node]){
        if (!yesno[i]){
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    int ans = 0, ind[size];
    for (int i = 1; i <= n; i++){
        if (!yesno[i]){
            ind[ans++] = i;
            dfs(i);
        }
    }

    cout << ans-1 << "\n";
    for (int i = 1; i < ans; i++){
        cout << ind[i-1] << " " << ind[i] << "\n";
    }
}