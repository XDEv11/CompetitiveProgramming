#include <iostream>
#include <vector>
#include <numeric>
#include <array>

using namespace std;

// Eulerian cycle
namespace D {
	int n, k;
	array<int, 26> nxt;
	vector<int> cycle{};

	void dfs(int u) {
		while (nxt[u] < k) {
			int v{nxt[u]++};
			dfs(v);
			cycle.push_back(v);
		}
	}

	void solve() {
		cin >> n >> k;
		fill(nxt.begin(), nxt.end(), 0);
		cycle.clear();

		dfs(0);

		int i{0};
		while (n--) {
			cout << char('a' + cycle[i]);
			i = (i + 1) % cycle.size();
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) D::solve();

	return 0;
}
