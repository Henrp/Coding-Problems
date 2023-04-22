#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
int small = 10000000;
string ans = "";

void solve(int l, int r)
{
    int len = r-l+1;

    for (int i = 0; i < small/2; i++){
        for (int i = 0; i < len; i++){
            ans += "R"; 
        }
        for (int i = 0; i < len; i++){
            ans += "L"; 
        }
    }
    
    for (int i = l; i <= r; i++){
        nums[i] -= small;
    }
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int a; cin >> a; 
        a-=2; //might be wrong
        nums.push_back(a);
    }

    int left, right;
    bool found = false;
    for (int i = 0; i < n; i++){
        if (!found && nums[i]){
            left = i;
            found = true;
        }

        if (found){
            if (nums[i]){
                right = i; 
                small = min(small, nums[i]);
            }
            
            if (!nums[i] || i == n-1){
                solve(left, right);
                found = false;
                small = 10000000;
                i = left-1;
            }
        } else {
            ans += "R";
        }
    }

    for (int i = 0; i < n; i++){
        ans += "L";
    }

    cout << ans;
}
