
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100000;
int ans[SIZE + 1];
vector<int> adj[SIZE + 1];
bool visited[SIZE + 1];

void dfs(int thiss, int past) {
	int len = adj[thiss].size();
	int temp = 1;
	for (int i : adj[thiss]) {
		if (i != past) {
			while (temp == ans[thiss] || temp == ans[past])
			{
				temp++;
			}
			ans[i] = temp;
			dfs(i, thiss);
			temp++;
		}
	}
}

int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);


	int n;
	cin >> n;
	int t1;
	int t2;
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2;

		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}


	dfs(1, 1);
	int maxAns = 0;
	for (int a : ans) {
		maxAns = max(maxAns, a);
	}
	cout << maxAns << "\n";
}