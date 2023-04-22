#include <bits/stdc++.h>
 
using namespace std;
 
struct edge {
    int cow; // which cow's choice 
    int to;
    bool is_first;
 
    edge() {};
    edge(int cow, int to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};
 
int N, M;
 
vector<edge> adj[100001];
bool visited_cycle[100001]; // array for cycle finding
bool visited[100001]; // visited array for finding which order of cows we should use
bool gets_cereal[100001]; 
 
int hungry_cows = 0;
queue<int> order;
int ignore_edge = -1;
int first_cereal = -1; // the cereal we start the search from, if the CC is not a tree then this must be on a cycle
 
void find_cycle(int cur, int prev = -1) {
    visited_cycle[cur] = true; 
 
    for (edge next : adj[cur]) {
        if (visited_cycle[next.to]) {
            if (first_cereal == -1 && next.to != prev) {
                if (next.is_first) {
                    first_cereal = next.to; 
                } else {
                    first_cereal = cur;
                }
                
                ignore_edge = next.cow; 
                order.push(next.cow);
                gets_cereal[next.cow] = true;
            }
        } else {
            find_cycle(next.to, cur);
        }
    }
}
 
 
void dfs(int cur) {
    visited[cur] = true;
    for (edge next : adj[cur]) {
        if (!visited[next.to] && next.cow != ignore_edge) { 
            gets_cereal[next.cow] = true;
            order.push(next.cow);
            dfs(next.to);
        }
    }
}
 
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(edge(i+1, b, false));
        adj[b].push_back(edge(i+1, a, true));
    }
 
    for (int i = 1; i <= M; ++i) {
        first_cereal = -1;
        ignore_edge = -1;
        if (!visited[i]) {
            find_cycle(i);
           
            if (first_cereal > 0) {
                dfs(first_cereal);
            } else {
                dfs(i);
            }
        }
    }
 
    for (int i = 1; i <= N; ++i) {
        if (!gets_cereal[i]) {
            ++hungry_cows;
            order.push(i);
        } 
    }
 
    cout << hungry_cows << endl;
    while (!order.empty()) {
        cout << order.front() << endl; 
        order.pop();
    }
 
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int cow, to;
    bool is_first;

    edge() {};
    edge(int cow, int to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};

queue<int> cows;
int starve_count = 0;

vector<edge> adj [100001];
bool visited[100001], cycle[10001], gets_cereal [100001];
int root_node = -1, ignore_edge = -1;

void find_cycle(int cur, int prev = -1)
{
    cycle[cur] = true;
    for (edge i : adj[cur]){
        if (cycle[i.to]){
            if (root_node == -1 && i.to != prev){
                if (i.is_first){
                    root_node = i.to;
                } else {
                    root_node = cur;
                }

                ignore_edge = i.cow;
                cows.push(i.cow);
                gets_cereal[i.cow] = true;
            }
        } else {
            find_cycle(i.to, cur);
        }
    }
}

void dfs(int cur)
{
    visited[cur] = true;
    for (edge i : adj[cur]){
        if (!visited[i.to] && i.cow != ignore_edge){
            gets_cereal[i.cow]= true;
            cows.push(i.cow);
            dfs(i.to);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(edge(i+1, b, false));
        adj[b].push_back(edge(i+1, a, true));
    }

    for (int i = 1; i <= m; i++){
        root_node = -1, ignore_edge = -1;
        if (!visited[i]){
            find_cycle(i);
            if (ignore_edge > 0){
                dfs(root_node);
            } else {
                dfs(i);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (!gets_cereal[i]){
            cows.push(i);
            starve_count++;
        }
    }

    cout << starve_count << "\n";
    while (!cows.empty()){
        cout << cows.front() << "\n";
        cows.pop();
    }
}   
*/
