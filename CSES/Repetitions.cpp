#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int temp = 1, ans = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == str[i+1]){
            temp++;
        } else {
            ans = max(ans, temp);
            temp = 1;
        }
    }

    cout << ans;
}