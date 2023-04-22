#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

long long countSetBit(long long a, long long b)
{
    long long c = (a&((1 << b) - 1)), count = 0;
    while (c > 0){
        if (c%2 == 1) count++;
        c/=2;
    }

    return count;
}

void solve()
{
    long long a, b; cin >> a >> b;

    long long ans = 100000000000000000;
    for (long long div = 0; (b >> div) > 0; div++){  
        long long num_op = 0, alt_a = a, div_b = (b >> div); 
        while (alt_a > div_b){ //this is the number of times we have to divide (notice we add 1 because a is odd)
            if (alt_a % 2 == 1){
                num_op++, alt_a++;
            }
            num_op++, alt_a/=2;
        }

        /*
        The process is split into three steps
        1. Divide
        2. Add
        3. Multiply

        We add before we multiply because it makes it more efficient; we are basically adding 2^n where n is the number of times we multiply
        */

        num_op += (div_b-alt_a) + (div) + countSetBit(b, div); //this is the number of times we have to add after we finish multiplying (at the end of all operations) the number of times we multiply and the number of times we have add before we multiply

        ans = min(ans, num_op);
    }

    cout << ans << "\n";
}

int main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
