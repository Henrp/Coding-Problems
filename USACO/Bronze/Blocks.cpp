#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    vector<string> dice (4);
    for (int i = 0; i < 4; i++) cin >> dice[i];

    while (n--){
        string want; cin >> want;

        vector<vector<int>> dice_num(want.length());
        for (int i = 0; i < want.length(); i++){
            for (int j = 0; j < 4; j++){
                if (dice[j].find(want[i]) != -1){
                    dice_num[i].push_back(j);
                }
            }
        }

        vector<int> freq(4, 0);
        vector<bool> taken(4, false);
        for (int i = 0; i < want.length(); i++){
            for (size_t j = 0; j < dice_num[i].size(); j++){
                freq[dice_num[i][j]]++;
            }
        }
        
        
        for (int i = 0; i < want.length(); i++){
            int curr = 1000;
            for (size_t j = 0; j < dice_num[i].size(); j++){
                if (!taken[dice_num[i][j]] && freq[dice_num[i][j]] < curr){
                    curr = dice_num[i][j];
                    freq[dice_num[i][j]]--;
                }
            }

            if (curr == 1000){
                cout << "NO" << "\n";
                break;
            }

            taken[curr] = true;

            if (i == want.length()-1){
                cout << "YES" << "\n";
            }
        }
        

    }
}