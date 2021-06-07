#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
	static constexpr long long MINIMUM{-1000000000};
	int n;
	cin >> n;
	vector<int> h(n + 1);
	vector<int> b(n + 1);
	h[0] = 0;
	for (int i{1}; i <= n; ++i) cin >> h[i];
	for (int i{1}; i <= n; ++i) cin >> b[i];

	vector<long long> dp(n + 1);
	dp[0] = MINIMUM;
	stack<pair<int, long long>> stk{};
	stk.emplace(0, 0);
	for (int i{1}; i <= n; ++i) {
		while (h[stk.top().first] > h[i]) {
			auto mx{stk.top().second};
			stk.pop();
			if (!stk.empty()) stk.top().second = max(stk.top().second, mx);
		}
		dp[i] = max(dp[stk.top().first], stk.top().second + b[i]);
		stk.emplace(i, dp[i]);
	}

	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
