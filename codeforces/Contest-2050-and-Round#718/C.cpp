#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> ans(n, vector<int>(n));
	for (int i{0}; i < n; ++i) {
		int k{0};
		for (int j{0}; i + j < n; ++j) {
			while (v[k] <= i) ++k;
			ans[i + j][j] = v[k], ++k;
		}
	}

	for (int i{0}; i < n; ++i) {
		for (int j{0}; j <= i; ++j) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
