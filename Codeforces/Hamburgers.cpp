#include <iostream>
#include <algorithm>
using namespace std;

long long bread, saus, cheese, bCost, sCost, cCost, bCount = 0, sCount = 0, cCount = 0;

long long compute(long long burgNum)
{
    long long cost = bCost * (max(0ll, burgNum*bCount - bread)) + sCost * (max(0ll, burgNum*sCount - saus)) + cCost * (max(0ll, burgNum*cCount - cheese));
    return cost;
}

int main()
{
    string hamb; cin >> hamb;
    cin >> bread >> saus >> cheese;
    cin >> bCost >> sCost >> cCost;

    for (char c : hamb){
        if (c == 'B'){
            bCount++;
        } else if (c == 'S'){
            sCount++;
        } else if (c == 'C'){
            cCount++;
        }
    }

    long long money; cin >> money;

    long long l = 0, r = 10000000000000;

    
    while (l < r){
        long long mid = (r-l+1)/2;
        if (l >= r) break;
        //cout << mid << "\n";
        if (compute(mid) <= money){
            l = mid;
        } else {
            r = mid-1;
        }
    }
    
   

}