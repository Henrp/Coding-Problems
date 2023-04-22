#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> desire, curr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;    
        curr.push_back(a);
    }
    for (int i = 0; i < n; i++){
        int a; cin >> a;    
        desire.push_back(a);
    }

    int ans = 0;
    while (true){
        bool same = true;
        for (int i = 0; i < n; i++){
            if (curr[i] != desire[i]) same = false;
        }
        if (same) break;

        int ind = lower_bound(desire.begin(), desire.end(), curr[curr.size()-1]) - desire.begin();
        curr.insert(curr.begin()+ind+1, curr[curr.size()-1]);
        curr.pop_back();
        ans++;
    }

    cout << ans;
}
/*
int main()
{
    int n; cin >> n;
    string desire = "", curr = "";

    for (int i = 0; i < n; i++){
        int a; cin >> a;    
        curr += to_string(a);
    }
    for (int i = 0; i < n; i++){
        int a; cin >> a;    
        desire += to_string(a);
    }
    
    reverse(curr.begin(), curr.end());
    reverse(desire.begin(), desire.end());

    int ans = 0;
    
    while (desire != curr){
        int ind = desire.find(curr[0]);
        curr.insert(ind+1, 1, curr[0]);

        curr.erase(curr.begin());
        ans++;
        
    }
    
    cout << ans;
}
*/