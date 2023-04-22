#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true){
        int T; cin >> T;
        if (T == -1) break;
        while (T--){
            int D, I, ans = 1; cin >> D >> I;
            for (int i = 0; i < D-1; i++){
                if (I%2 == 1){
                    ans *= 2; I = (I+1)/2;
                } else {
                    ans = (ans*2)+1; I/=2;
                }
            }
            cout << ans << "\n";
        }
    }
}