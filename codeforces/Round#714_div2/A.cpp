#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> ans(n); iota(ans.begin(), ans.end(), 1);

	for (int i{1}; i + 1 < n; i += 2)
		if (k) swap(ans[i], ans[i + 1]), --k;
		else break;

	if (!k) {
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	} else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
