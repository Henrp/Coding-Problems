#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> nums ((1 << 18), false); 
    vector<int> ans ({0});

    nums[0] = true;
    int n, x;
    cin >> n >> x;
    for (int i = 1; i < (1 << n); i++){
        if (nums[i ^ x]) continue; //to make sure its not repeated
        ans.push_back(i);
        nums[i] = true;
    }

    cout << ans.size()-1 << "\n";
    for (int i = 1; i < ans.size(); i++){
        cout << (ans[i]^ans[i-1]) << " ";
    }
}