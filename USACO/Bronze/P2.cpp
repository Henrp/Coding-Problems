#include <iostream>
#include <algorithm>
using namespace std;

bool solve(){
    int dice_a[4], dice_b[4];

    for (int i = 0; i < 4; i++){
        cin >> dice_a[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> dice_b[i];
    }

    sort(dice_a, dice_a+4); sort(dice_b, dice_b+4);

    int a_score = 0, b_score = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (dice_a[i] > dice_b[j]){
                a_score++;
            } else if (dice_a[i] < dice_b[j]){
                b_score++;
            }
        }
    }

    if (a_score == b_score){
        return false;
    } else {
        for (int i = 1; i <= 10; i++){
            for (int j = 1; j <= 10; j++){
                for (int k = 1; k <= 10; k++){
                    for (int l = 1; l <= 10; l++){
                        int dice_c[] = {i, j, k, l};

                        if (a_score > b_score){
                            int score_a = 0, score_b = 0, score_c = 0;
                            for (int x = 0; x < 4; x++){
                                for (int y = 0; y < 4; y++){
                                    if (dice_a[x] > dice_c[y]){
                                        score_a++;
                                    } else if (dice_a[x] < dice_c[y]){
                                        score_c++;
                                    }
                                }
                            } 

                            if (score_a >= score_c){
                                continue;
                            }

                            score_c = 0;
                            for (int x = 0; x < 4; x++){
                                for (int y = 0; y < 4; y++){
                                    if (dice_b[x] > dice_c[y]){
                                        score_b++;
                                    } else if (dice_b[x] < dice_c[y]){
                                        score_c++;
                                    }
                                }
                            } 

                            if (score_b > score_c){
                                return true;
                            }
                        } else {
                            int score_a = 0, score_b = 0, score_c = 0;
                            for (int x = 0; x < 4; x++){
                                for (int y = 0; y < 4; y++){
                                    if (dice_b[x] > dice_c[y]){
                                        score_b++;
                                    } else if (dice_b[x] < dice_c[y]){
                                        score_c++;
                                    }
                                }
                            } 

                            if (score_b >= score_c){
                                continue;
                            }

                            score_c = 0;
                            for (int x = 0; x < 4; x++){
                                for (int y = 0; y < 4; y++){
                                    if (dice_a[x] > dice_c[y]){
                                        score_a++;
                                    } else if (dice_a[x] < dice_c[y]){
                                        score_c++;
                                    }
                                }
                            } 

                            if (score_a > score_c){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        if (solve()){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}