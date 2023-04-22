#include <iostream>
#include <vector>
using namespace std;

int mTime, n, ans = 0;
vector<int> cds, sub, ans_v;
void perm(int ind = 0, int sum = 0)
{
    if (sum > mTime){
        return;
    }
    if (ind == n){
        if (sum > ans){
            ans = sum;
            ans_v = sub;
        }
        return;
    }

    sub.push_back(cds[ind]);
    perm(ind+1, sum + cds[ind]);
    sub.pop_back();
    perm(ind+1, sum);
}

int main()
{
     while (cin >> mTime >> n){
        ans = 0;
        for (int i = 0; i < n; i++){
            int a; cin >> a; 
            cds.push_back(a);
        }

        perm();

        for (int i : ans_v) cout << i << " ";
        cout << "sum:" << ans << "\n";
        cds.clear();
     }
}