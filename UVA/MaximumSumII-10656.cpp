#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    int n;
    while (cin >> n){
        if (n == 0) break;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a != 0) v.push_back(a);
        }

        if (v.empty()){
            cout << 0 << "\n";
            continue;
        }
        for (auto const& i : v){
            int ind = &i - &v.front();
            if (ind == v.size()-1) cout << i;
            else cout << i << " ";
        }
        cout << "\n";
    }
}