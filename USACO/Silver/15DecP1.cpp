#include <iostream>
#include <vector>
using namespace std;

int msize = 101, ans = 0;
vector<vector<vector<pair<int, int>>>> switches (msize, vector<vector<pair<int, int>>>(msize));
vector<vector<int>> visited (msize+1, vector<int>(msize+1, 0)), light (msize+1, vector<int>(msize+1, 0));

void FF(int c, int r)
{
    if (c <= 0 || r <= 0 || c >= msize || c >= msize || visited[c][r] || !light[c][r]) return;
    visited[c][r] = 1;

    for (auto l : switches[c][r]){
        if (!light[l.first][l.second]){
            ans++;
        }
        light[l.first][l.second] = 1;

        if (visited[l.first][l.second-1] || visited[l.first][l.second+1] || visited[l.first-1][l.second] || visited[l.first+1][l.second]){
            FF(l.first, l.second);
        }
    }

    FF(c+1, r);
    FF(c-1, r);
    FF(c, r+1);
    FF(c, r-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    freopen("lightson.in","r",stdin); 
    freopen("lightson.out","w",stdout); 
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, a, b; cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    light[1][1] = 1;

    FF(1, 1);

    cout << ans+1;
}