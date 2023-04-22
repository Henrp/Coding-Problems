#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, char> convert;
int distinct = 0;

int ans = 0;

void solve()
{
    string inp, out; cin >> inp >> out;
    for (int i = 0; i < inp.length(); i++){
        auto search = convert.find(inp[i]);
        if (search == convert.end()){
            convert.insert({inp[i], out[i]});
            //add distinct counter
        } else {
            if (convert[inp[i]] != out[i]){
                cout << -1 << "\n";
                return;
            }
        }
    } // DONE

    distinct = convert.size();

    for (auto& [key, val] : convert){
        auto search = convert.find(val);
        if (search != convert.end() && key != val){
            if (convert[val] == key){
                ans += 3;
                convert[]
                distinct++;
                /*
                if (distinct > 52){
                    cout << -1 << "\n";
                    return;
                }
                */
            } else if (convert[val] != key){
                key = val;
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while (t--){
        solve();
        ans = 0, distinct = 0;
        convert.clear();
    }
}