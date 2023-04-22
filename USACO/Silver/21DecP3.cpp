#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> inter;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        inter.push_back({a, b});
    }

    vector<long long> start (m*2+1, 0), end(m*2+1, 0);

    vector<long long> freq1 (m+1, 0);
    for (int i = 0; i < n; i++){
        freq1[inter[i].first]++;
    }
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            start[i+j] += freq1[i] * freq1[j];
        }
    }

    vector<long long> freq2 (m+1, 0);
    for(int i = 0; i < n; i++){
        freq2[inter[i].second]++;
    }
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            end[i+j] += freq2[i] * freq2[j];
        }
    }

    long long count = 0;
    for (int i = 0; i <= m*2; i++){
        count += start[i];
        cout << count << "\n";
        count -= end[i];
    }
}