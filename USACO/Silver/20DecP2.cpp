#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> east, north;

bool comp(vector<int>& a, vector<int>& b)
{
    if (a[1] < b[1]) return true;
    return false;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        int a, b; cin >> a >> b;
        if (c == 'E'){
            east.push_back({a, b, i});
        } else if (c == 'N'){
            north.push_back({a, b, i});
        }
    }

    sort(east.begin(), east.end(), comp);
    sort(north.begin(), north.end());

    /*
    //ACWP 
    for (auto i : east){
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
    */
    
    
   
    vector<bool> eStop(east.size(), false), nStop(north.size(), false);

    vector<int> ans (n, 0);
    for (size_t i = 0; i < east.size(); i++){
        for (size_t j = 0; j < north.size(); j++){
            int a = east[i][0], b = east[i][1];
            int c = north[j][0], d = north[j][1];

            int eInd = east[i][2], nInd = north[j][2];

            if (!eStop[i] && !nStop[j] && a < c && b > d){
                if (c-a > b-d){ 
                    eStop[i] = true;
                    ans[nInd] += (ans[eInd] + 1);
                } else if (c-a < b-d){
                    nStop[j] = true;
                    ans[eInd] += (ans[nInd] + 1);
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }
    
}   