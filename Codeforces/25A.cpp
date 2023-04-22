#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> ar;

    int ecount = 0, ocount = 0, eind, oind;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (a%2 == 0) ecount++, eind = i;
        else ocount++, oind = i;
        ar.push_back(a);
    }

    if (ecount == 1) cout << eind+1;
    else cout << oind+1;
}