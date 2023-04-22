#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t >> a >> b;

    vector<int> full (t + 1, 0);
    for (int i = 1; i <= t; i++){
         if (i - a >= 0){
             full[i] = max(full[i], full[i-a] + a);
         } 

         if (i - b >= 0){
             full[i] = max(full[i], full[i-b] + b);
         }
    }
}