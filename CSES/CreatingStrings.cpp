#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str;
int char_count[26];
vector<string> ans;
void perm(string s)
{   
    if (s.length() == str.length()){
        ans.push_back(s);
        return;
    } 
        for (int i = 0; i < 26; i++){
            if (char_count[i] > 0){
                char_count[i]--;
                perm(s + char('a' + i));
                char_count[i]++;
            }
        }
    
}

int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++){
        char_count[int(str[i]) - 97]++;
    }

    perm("");

    cout << ans.size() << "\n";
    for (string s : ans) cout << s << "\n";
}