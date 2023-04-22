#include <iostream>
using namespace std;

int cDir[] = {1, 0, -1, 0}, rDir[] = {0, 1, 0, -1}, ans = 0;
bool vis[9][9];

const int pathCount = 48;
int definedPath[pathCount];

void BT(int a, int b, int num)
{
    //conditionals
    if (vis[a-1][b] && vis[a+1][b] && !vis[a][b+1] && !vis[a][b-1]) return;
    if (!vis[a-1][b] && !vis[a+1][b] && vis[a][b+1] && vis[a][b-1]) return;

    if (a == 7 && b == 1){
        if (num == pathCount) ans++;
        return;
    }

    //recursion
    vis[a][b] = true;

    if (definedPath[num] >= 0){
        int x = a+cDir[definedPath[num]], y = b+rDir[definedPath[num]];
        if (!vis[x][y]) BT(x,y, num+1);
    } else {
        for (int i = 0; i < 4; i++){
            int x = a+cDir[i], y = b+rDir[i];
            if (vis[x][y]) continue;
            BT(x,y, num+1);
        }
    }

    vis[a][b] = false;
}

int main()
{
    string path; cin >> path;
    for (int i = 0; i < path.length(); i++){
        if (path[i] == 'D') definedPath[i] = 0;
        else if (path[i] == 'R') definedPath[i] = 1;
        else if (path[i] == 'U') definedPath[i] = 2;
        else if (path[i] == 'L') definedPath[i] = 3;
        else definedPath[i] = -1;
    }

    for (int i = 0; i < 9; i++){
        vis[i][8] = vis[8][i] = vis[i][0] = vis[0][i] = true;
    }
    for (int i = 1; i < 8; i++){
        for (int j = 1; j < 8; j++){
            vis[i][j] = false;
        }
    }

    BT(1, 1, 0);
    cout << ans;
}