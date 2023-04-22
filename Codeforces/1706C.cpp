#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
long long ans = 0;
 
void odd(vector<int> f)
{
    for (int i = 1; i < f.size()-1; i+=2){
        ans += max(0, max(f[i-1], f[i+1])-f[i]+1);
    }
}
void even(vector<int> f)
{
    long long total = 0;
    for (int i = 1; i < f.size()-1; i+=2){
        total += max(0, max(f[i-1], f[i+1])-f[i]+1); 
    }
    ans = total;
    for (int i = f.size()-2; i > 0; i-=2){
        total -= max(0, max(f[i-2], f[i])-f[i-1]+1);
        total += max(0,max(f[i-1], f[i+1])-f[i]+1);
        ans = min(ans, total);
    }
}
 
void solve()
{
    int n; cin >> n;
    vector<int> floors;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        floors.push_back(a);
    }
 
    if (n%2 == 0) even(floors);
    else odd(floors);
}
 
int main()
{
    int t; cin >> t;
    while(t--){
        solve();
        cout << ans << "\n";
        ans = 0;
    }
}