#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("bcount.in","r",stdin); 
    freopen("bcount.out","w",stdout); 

    int n, q; cin >> n >> q;
    vector<vector<int>> cows (n, vector<int>(3, 0));
    int lol; cin >> lol; lol--; cows[0][lol]++;
    for (int i = 1; i < n; i++){
        int a; cin >> a; a--;
        cows[i][a] = cows[i-1][a] + 1;
        for (int j = 0; j < 3; j++){
            if (j != a){
                cows[i][j] = cows[i-1][j];
            }
        }
    }

    while(q--){
        int a, b; cin >> a >> b; a-=2, b--;
        if (a == -1){
            for (int i = 0 ; i < 2; i++) cout << cows[b][i] << " ";
            cout << cows[b][2];
        }
        else {
            for (int i = 0; i < 2; i++) cout << cows[b][i] - cows[a][i] << " ";
            cout << cows[b][2] - cows[a][2];
        }
        cout << "\n";
    }
}