#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> graph;
vector<vector<int>> dir;
queue<pair<int, int>> path;

int hori[] {1, 0, -1, 0}, vert[] = {0, 1, 0, -1};
int n, m;

void bfs()
{
    while (!path.empty()){
        pair<int, int> parent = path.front(); path.pop();

        for (int i = 0; i < 4; i++){
            pair<int, int> child = {parent.first + hori[i], parent.second + vert[i]};
            if (child.first < 0 || child.second < 0 || child.first >= n || child.second >= m || !graph[child.first][child.second]) continue;
            if (child.first == 0 || child.second == 0 || child.first == n-1 || child.second == m-1){
                
            }
            path.push(child);
            graph[child.first][child.second] = false;
            dir[child.first][child.second] = i;
        }


    }
}

int main()
{
    cin >> n >> m;

    graph.resize(n, vector<bool> (m, true));

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;

            if (c == '#'){
                graph[i][j] = false;
            } else if (c == 'A'){

            } else if (c == 'M'){

            }
        } 
    }

    bfs();
}