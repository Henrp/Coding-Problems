#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("cardgame.in","r",stdin); 
	freopen("cardgame.out","w",stdout); 
    int n;
    cin >> n;

    vector<int> l_elsie;
    vector<int> r_elsie;
    vector<int> dummy;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (i <= n/2){
            l_elsie.push_back(x);
        } else {
            r_elsie.push_back(x);
        }
        
        dummy.push_back(x);
    }
    sort(dummy.rbegin(), dummy.rend());

    int ind = 0;
    vector<int> l_bessie;
    vector<int> r_bessie;
    for (int i = 2*n; i > 0; i--){
        if (ind < n && i == dummy[ind]){
            ind++;
        } else if (l_bessie.size() < n/2){
            l_bessie.push_back(i);
        } else {
            r_bessie.push_back(i);
        }
    }

    sort(l_elsie.rbegin(), l_elsie.rend());
    sort(r_elsie.begin(), r_elsie.end());
    sort(r_bessie.begin(), r_bessie.end());

    int ans = 0;

    int l_ind = 0;
    for (size_t i = 0; i < l_elsie.size(); i++){
        if (l_elsie[i] < l_bessie[l_ind]){
            l_ind++; ans++;
        }
    }
    
    int r_ind = 0;
    for (size_t i = 0; i < r_elsie.size(); i++){
        if (r_elsie[i] > r_bessie[r_ind]){
            r_ind++; ans++;
        }
    }

    cout << ans << endl;  
}