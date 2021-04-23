#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			cin >> b[i][j];

	using pq_t = tuple<int, int, int>;
	priority_queue<pq_t> pq{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			pq.emplace(b[i][j], i, j);
			if (pq.size() > m) pq.pop();
		}

	for (int k{0}; k < m; ++k) {
		auto [v, i, j]{pq.top()}; pq.pop();
		ans[i][k] = v;
		b[i][j] = 0;
	}
	for (int i{0}; i < n; ++i) {
		int k{0};
		for (int j{0}; j < m; ++j) {
			if (!b[i][j]) continue;
			while (ans[i][k]) ++k;
			ans[i][k] = b[i][j];
		}
	}

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			cout << ans[i][j] << " \n"[j == m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
