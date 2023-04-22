#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//Search up on the web "Monotonous stack" for more detailed explanation
int64_t ans = 0;
void mono_stack(const int ar[], const int size)
{
    stack<int> cows;

    for (int i = 0; i < size; i++){
        while (!cows.empty() && ar[cows.top()] < ar[i]) cows.pop();
        //We need to account for the cows right next to each other
        if (!cows.empty()) ans += (i - cows.top() + 1);
        cows.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    mono_stack(ar, n);
    reverse(ar, ar + n);
    mono_stack(ar, n);

    cout << ans << "\n";
}