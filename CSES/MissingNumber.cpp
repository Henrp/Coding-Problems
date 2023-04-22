#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool ar[n];

    for (int i = 0; i < n; i++){
        ar[i] = true;
    }

    for (int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        ar[a-1] = false;
    }

    for (int i = 0; i < n; i++){
        if (ar[i]){
            cout << i+1;
        }
    }
}