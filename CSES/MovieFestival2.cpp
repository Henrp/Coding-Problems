#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second < b.second){
        return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> t_movie;
    for (int i = 0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        t_movie.push_back({a, b});
    }

    sort(t_movie.begin(), t_movie.end(), comp);

    multiset<int> time;
    for (int i = 0; i < k; i++){
        time.insert(0);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        //Finding the upper_bound to find the person who had the latest ending because 
        //we want to maximize the amount of movie each person can watch.
        //If we were to choose someone who doesn't have the latest it will decrease the range of time that person can watch
        //So, if we choose the latest, the people can watch more movies
        auto it = time.upper_bound(t_movie[i].first);

        //If the t_movie[i].first is smaller than all elements in time, 
        //we want to skip it because all the people already gone past that time, 
        //restricting them from watching at that time period.
        if (it == time.begin()) continue;

        //We are taking --it because we took the upper_bound, not lower_bound
        time.erase(--it);
        time.insert(t_movie[i].second); 
        ans++;
    }

    cout << ans << "\n";
}