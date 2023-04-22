#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> farm;

int main()
{
    int k, m, n; cin >> k >> m >> n;
    for (int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        farm.push_back({a, b});
    }

    for (int i = 0; i < m; i++){
        int a; cin >> a;
        farm.push_back({a, -1});
    }

    sort(farm.begin(), farm.end());

    vector<int> val, oneCow;
    int temp = 0, outer = -1;
    for (size_t i = 0; i < farm.size(); i++){
        if (farm[i].second == -1){
            if (outer != -1) val.push_back(temp);
            else {
                outer = temp;
                oneCow.push_back(temp);
            }
            temp = 0;
            continue;
        }
        temp += farm[i].second;

        if (i == farm.size()-1) {
            oneCow.push_back(temp);
            temp += outer;
            val.push_back(temp);
        }
    }

    int left, right, count = 0;
    for (size_t i = 0; i < farm.size(); i++){
        if (farm[i].second == -1) count++;
        if (farm[i].second == -1 && count == 1) left = i;
        if (farm[i].second == -1 && count == m) right = i;
    }

    for (int i = i+1; i < right; i++){
        if (farm[i].second != -1) oneCow.push_back(farm[i].second);
    }


    for (int i : val) cout << i << " ";   
    cout << "\n";
    for (int i : oneCow) cout << i << " ";
}