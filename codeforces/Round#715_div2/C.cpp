#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	vector<vector<long long>> dp(n, vector<long long>(n, 0));
	for (int i{n - 1}; i >= 0; --i)
		for (int j{i + 1}; j < n; ++j)
			dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + v[j] - v[i];

	cout << dp[0][n - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
