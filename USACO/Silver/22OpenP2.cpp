#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int q_num;
    cin >> q_num;
  
    for (int i = 0; i < q_num; i++){
        string query;
        cin >> query;

        vector<int> let (19, 0);
        for (int j = 0; j < query.length(); j++){
            let[int(query[j]) - 96]++;
        }

        string s_aft = "", t_aft = "";
        for (int j = 0; j < s.length(); j++){
            if (let[int(s[j]) - 96] > 0) s_aft += s[j];
        }
        for (int j = 0; j < t.length(); j++){
            if (let[int(t[j]) - 96] > 0) t_aft += t[j];
        }

        if (s_aft == t_aft) cout << "Y";
        else cout << "N";
    }
}