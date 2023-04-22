#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    int t; cin >> t;

    vector<vector<int>> blocks;
    vector<int> temp;
    set<int> s;
    
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            temp.push_back(a);
            s.insert(a);
        }
        blocks.push_back(temp);
        temp.clear();
    }

    vector<vector<int>> split;
    int counter = 0;
    for (int i = 0; i < blocks.size(); i++){
        for (int j = 0; j < blocks[i].size()-1; j++){
            temp.push_back(blocks[i][j]);

            int dis1 = distance(s.begin(), s.find(blocks[i][j]));
            int dis2 = distance(s.begin(), s.find(blocks[i][j+1]));

            if ((blocks[i][j] > blocks[i][j+1]) || (dis2 - dis1 != 1)){
                split.push_back(temp);
                temp.clear();
                counter++;
            }

            if (j == blocks[i].size()-2){
                temp.push_back(blocks[i][j+1]);
                split.push_back(temp);
            }
        }
        temp.clear();
    }

    cout << counter << " " << split.size()-1;
}