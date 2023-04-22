#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> val;
int n, x, l_ans, r_ans;

bool twoP(int i)
{
    int l = i+1, r = n-1;
    while (l < r){
        if (val[i].first + val[l].first + val[r].first == x){
            l_ans = l, r_ans = r;
            return true;
        }
        else if (val[i].first + val[l].first + val[r].first > x) r--;
        else l++;
    }
    return false;
}

int main()
{
    cin >> n >> x;
    val.resize(n);
    for (int i = 0; i < n; i++){
        cin >> val[i].first; 
        val[i].second = i;
    }
    sort(val.begin(), val.end());

    for (int i = 0; i < n-3; i++){
        if (twoP(i)) cout << val[i].second+1 << " " << val[l_ans].second+1 << " " << val[r_ans].second+1;
        else {
            cout << "IMPOSSIBLE";
        }
    }
}