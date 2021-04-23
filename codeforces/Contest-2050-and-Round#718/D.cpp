#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> h(n, vector<int>(m - 1));
	vector<vector<int>> v(n - 1, vector<int>(m));
	for (auto& vt : h)
		for (auto& x : vt) cin >> x;
	for (auto& vt : v)
		for (auto& x : vt) cin >> x;

	if (k & 1) {
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) cout << -1 << " \n"[j == m - 1];
		return ;
	}
	k /= 2;

	vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(m, numeric_limits<int>::max())));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			dp[0][i][j] = 0;

	for (int _k{1}; _k <= k; ++_k)
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) {
				if (i - 1 >= 0)
					dp[_k][i][j] = min(dp[_k][i][j], dp[_k - 1][i - 1][j] + v[i - 1][j]);
				if (i + 1 < n)
					dp[_k][i][j] = min(dp[_k][i][j], dp[_k - 1][i + 1][j] + v[i][j]);
				if (j - 1 >= 0)
					dp[_k][i][j] = min(dp[_k][i][j], dp[_k - 1][i][j - 1] + h[i][j - 1]);
				if (j + 1 < m)
					dp[_k][i][j] = min(dp[_k][i][j], dp[_k - 1][i][j + 1] + h[i][j]);
			}

	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) cout << 2 * dp[k][i][j] << " \n"[j == m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
