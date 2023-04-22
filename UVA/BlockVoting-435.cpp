#include <iostream>
#include <vector>
using namespace std;

vector<int> party, power; 
vector<pair<int, int>> temp;
vector<vector<pair<int, int>>> subset;
int total_vote = 0;

void find_subsets(int n)
{
    if (n == party.size()) {
        subset.push_back(temp);
        return;
    }

    find_subsets(n+1);
    temp.push_back({party[n], n});
    find_subsets(n+1);
    temp.pop_back();
}

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        total_vote += a;
        party.push_back(a);
    }

    find_subsets(0);

    power.resize(party.size(), 0);
    
    for (auto i : subset){
        int vote_num = 0;
        for (auto j : i){
            vote_num += j.first;
        }

        if (vote_num*2 > total_vote){
            for (auto j : i){
                if ((vote_num-j.first)*2 <= total_vote){
                    power[j.second]++;
                }
            }
        }
    }

    
    for (int i = 0; i < power.size(); i++){
        cout << "party " << i+1 << " has power index " << power[i] << "\n";
    }
}

int main()
{
    int T; cin >> T;
    while (T--){
        solve();
        party.clear(), power.clear(), temp.clear(), subset.clear(); 
        total_vote = 0;
        if (T > -1){
            cout << "\n";
        }
    }
}