#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    vector<int> set1, set2;
    if (n%2 == 0){
        if ((n/2)%2 == 0){
            cout << "YES" << "\n";
            for (int i = 1; i <= n; i++){
                if (i % 2 == 0){
                    set1.push_back(i);
                } else {
                    set2.push_back(i);
                }
            }
            for (int i = 0; i < n/4; i++){
                swap(set1[i], set2[i]);
            }
            cout << set1.size() << "\n";
            for (int i = 0; i < n/2; i++){
                cout << set1[i] << " ";
            }
            cout << "\n";

            cout << set2.size() << "\n";
            for (int i = 0; i < n/2; i++){
                cout << set2[i] << " ";
            }    
        } else {
            cout << "NO";
        }
    } else {
        if ((n - n/2) % 2 == 0){
            cout << "YES" << "\n";
            for (int i = 1; i <= n; i++){
                if (i % 2 == 0){
                    set1.push_back(i);
                } else {
                    set2.push_back(i);
                }
            }

            for (int i = 0; i < (n - n/2)/2; i++){
                swap(set1[i], set2[i+1]);
            }

            cout << set1.size() << "\n";
            for (int i = 0; i < n/2; i++){
                cout << set1[i] << " ";
            }
            cout << "\n";

            cout << set2.size() << "\n";
            for (int i = 0; i < n/2+1; i++){
                cout << set2[i] << " ";
            }
        } else {
            cout << "NO";
        }
    }
}