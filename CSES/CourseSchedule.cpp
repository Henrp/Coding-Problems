#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX], topo_sort;
bool visited[MAX];

void dfs(int node)
{
	for (int i : graph[node]){
		if (!visited[i]){
			visited[i] = true;
			dfs(i);
		}
	}

	topo_sort.push_back(node);
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		graph[a-1].push_back(b-1);
	}

	for (int i = 0; i < n; i++){
		if (!visited[i]){
			visited[i] = true;
			dfs(i);
		}
	}
	reverse(topo_sort.begin(), topo_sort.end());
	
	vector<int> ind (n);
	for (int i = 0; i < n; i++){
		ind[topo_sort[i]] = i;
	}
	for (int i = 0; i < n; i++){
		for (int j : graph[i]){
			if (ind[i] >= ind[j]){
				cout << "IMPOSSIBLE";
				exit(0);
			}
		}
	}

	for (int i : topo_sort) cout << i+1 << " ";
}