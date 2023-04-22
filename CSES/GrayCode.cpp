#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < (1 << n); i++){
        int val = (i^(i>>1)); //converts binary to gray
        bitset<32> r(val);
        string str = r.to_string();
        cout << str.substr(32-n) << "\n";
    }
}