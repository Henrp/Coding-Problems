#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("highcard.in","r",stdin); 
    freopen("highcard.out","w",stdout); 
    
    int n; cin >> n;
    vector<bool> done (n*2+1, false);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        done[a] = true;
    }

    vector<int> elsie, bessie;
    for (int i = 1; i <= n*2; i++){
        if (done[i]) elsie.push_back(i);
        else bessie.push_back(i);
    }

    int eInd = 0, bInd = 0, points = 0;
    while (eInd < n && bInd < n){
        if (elsie[eInd] < bessie[bInd]) points++, eInd++, bInd++;
        else bInd++;
    }

    cout << points;
}