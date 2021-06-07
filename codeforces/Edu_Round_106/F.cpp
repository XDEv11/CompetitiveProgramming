#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace F {
	static constexpr long long m{998244353};

	int n, k;
	vector<vector<int>> adj{};
	vector<vector<long long>> dp{};

	// tree diameter
	int dfs(int u, int w = -1) {
		dp[u][0] = 1;
		int mx{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;

			auto len{dfs(v, u)};

			typename decltype(dp)::value_type tmp(max(mx, len + 1) + 1, 0);
			for (int i{0}; i <= mx; ++i)
				for (int j{0}; j <= len; ++j) {
					if (i + j + 1 <= k) { // remain
						tmp[max(i, j + 1)] += dp[u][i] * dp[v][j];
						tmp[max(i, j + 1)] %= m;
					}
					if (i <= k && j <= k) { // cut
						tmp[i] += dp[u][i] * dp[v][j];
						tmp[i] %= m;
					}
				}

			mx = max(mx, len + 1);
			for (int i{0}; i <= mx; ++i) dp[u][i] = tmp[i];
		}
		return mx;
	}

	void solve() {
		cin >> n >> k;
		adj.assign(n, {});
		dp.assign(n, typename decltype(dp)::value_type(n, 0));

		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		long long ans{0};
		dfs(0);
		for (int i{0}; i <= k; ++i) ans = (ans + dp[0][i]) % m;

		cout << ans << '\n';
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) F::solve();

	return 0;
}
