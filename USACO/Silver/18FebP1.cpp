#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("reststops.in","r",stdin); 
    freopen("reststops.out","w",stdout); 
    

    long long L, N, r_F, r_B; cin >> L >> N >> r_F >> r_B;

    vector<pair<long long, long long>> rStops;
    for (long long i = 0; i < N; i++){
        long long pos, val; cin >> pos >> val;
        rStops.push_back({val, pos});
    }

    sort(rStops.rbegin(), rStops.rend());

    long long inc = r_F-r_B;


    long long cur_pos = 0, point = 0;
    for (auto stops : rStops){
        if (stops.second <= cur_pos) continue;

        long long time = (stops.second - cur_pos)*inc;
        point += (time*stops.first);

        cur_pos = stops.second;
    }

    cout << point;
    
}