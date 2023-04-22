#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char grid[3][3];
    int abc[26+1];
    
    for (int i = 0; i < 27; i++){
        abc[i] = 0;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> grid[i][j];
            abc[int(grid[i][j]) - 64]++;
        }
    }

    
    char ans[3][3];
    int ans_abc[26+1];

    for (int i = 0; i < 27; i++){
        ans_abc[i] = 0;
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> ans[i][j];
            ans_abc[int(ans[i][j]) - 64]++;
        }
    }

    int green = 0, yellow = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i][j] == ans[i][j]){
                green++;
                abc[int(grid[i][j]) - 64]--;
                ans_abc[int(ans[i][j]) - 64]--;
            }
        }
    }

    for (int i = 1; i < 27; i++){
        yellow += min(ans_abc[i], abc[i]);
    }

    cout << green << "\n" << yellow;
}