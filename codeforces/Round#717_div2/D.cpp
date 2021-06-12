#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static constexpr int maxn{100000};
static vector<vector<int>> pd(maxn + 1); // prime divisor
static void build() {
	for (int i{2}; i <= maxn; ++i) {
		if (!pd[i].empty()) continue;
		for (int j{i}; j <= maxn; j += i) pd[j].push_back(i);
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> t(maxn + 1, 0);
	vector<int> prev(n + 1, 0);
	for (int i{1}; i <= n; ++i)
		for (auto& x : pd[v[i]]) {
			prev[i] = max(prev[i], t[x]);
			t[x] = i;
		}

	/* 2^17 > 1e5 (max n) */
	vector<vector<int>> dp(18, vector<int>(n + 1));
	dp[0][0] = 0;
	for (int i{1}; i <= n; ++i) dp[0][i] = max(dp[0][i - 1], prev[i]);

	for (int k{1}; k <= 17; ++k)
		for (int i{0}; i <= n; ++i) {
			dp[k][i] = dp[k - 1][dp[k - 1][i]];
		}

	while (q--) {
		int l, r, ans{0};
		cin >> l >> r;
		for (int k{17}; k >= 0; --k)
			if (l <= dp[k][r]) {
				ans += (1 << k);
				r = dp[k][r];
			}
		cout << ans + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	build();

	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
