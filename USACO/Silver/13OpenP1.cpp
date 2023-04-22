#include <iostream>
#include <algorithm>
using namespace std;

char grid[501][501];
pair<int, int> start, finish;

char dir = {'R', 'U', 'L', 'D'};

int ans = 999999, counter = 0;
void FF(int r, int c)
{
    if (r == finish.first && c == finish.second){
        ans = min(ans, counter);
        return;
    }

    for (char d : dir){
        if (d == 'R' && grid[r-1][c+1]){
            FF(r, c+1);
        } else if (d == 'U'){

        } else if (d == 'L'){
            FF(r, c-1);
        } else {

        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'C') start = {i, j};
            if (grid[i][j] == 'D') finish = {i, j};
        }
    }


}