#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    pair<int, int> begin, end;
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < m; j++){ 
            cin >> graph[i][j]; 

            if (graph[i][j] == 'A'){
                begin = {i, j};
            } else if (graph[i][j] == 'B'){
                end = {i, j};
            } else if (graph[i][j] == '#'){
                visited[i][j] = true;
            }
        }
    }

    int xd[4] = {1, 0 , -1, 0}, yd[4] = {0, 1, 0, -1};
    queue<pair<int, int>> route;
    vector<vector<int>> dir (n, vector<int> (m));
    route.push(begin);
    while (!route.empty()){
        pair<int, int> parent = route.front();
        route.pop();

        for (int i = 0; i < 4; i++){
            pair<int, int> child = {parent.first + xd[i], parent.second + yd[i]};
            if (child.first < 0 || child.second < 0 || child.first >= n || child.second >= m || visited[child.first][child.second]) continue;

            route.push(child);
            visited[child.first][child.second] = true;
            dir[child.first][child.second] = i;
        }
    }

    if (visited[end.first][end.second]){
        cout << "YES" << "\n";

        vector<int> route_dir;
        while (end != begin){
            route_dir.push_back(dir[end.first][end.second]);
            end = {end.first - xd[dir[end.first][end.second]], end.second - yd[dir[end.first][end.second]]};
        }
        reverse(route_dir.begin(), route_dir.end());

        cout << route_dir.size() << "\n";

        string ans_dir = "DRUL";
        for (int i : route_dir){
            cout << ans_dir[i];
        }
    } else {
        cout << "NO";
    }


}