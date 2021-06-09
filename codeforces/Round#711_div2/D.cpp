#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, long long, long long>> v(n);
	for (auto& [t, x, y] : v) cin >> t >> x >> y;

	vector<int> ans(m + 1, -1);
	ans[0] = 0;
	for (int i{1}; i <= n; ++i) {
		auto& [t, x, y]{v[i - 1]};
		for (int j{0}; j <= m; ++j) {
			if (ans[j] == -1 || ans[j] == i) continue; // unvisited
			long long k{j};
			auto c{y};
			while (c--) {
				t == 1 ? k = k * 100000 + x : k *= x;
				k = k / 100000 + bool(k % 100000);

				if (k > m) break; // exceed m
				if (ans[k] != -1 && ans[k] != i) break; // another visited node
				ans[k] = i;
			}
		}
	}

	for (int j{1}; j <= m; ++j) cout << ans[j] << " \n"s[j == m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
