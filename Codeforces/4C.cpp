#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> names;
    int n; cin >> n;
    string str;
    for (int i = 0; i < n; i++){
        cin >> str;
        if (names.find(str) == names.end()){
            names.insert({str, 1});
            cout << "OK" << "\n";
        } else {
            cout << str << names[str] << "\n";
            names[str]++;
        }
    }
}