#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n - 1; ++i) {
		int t{min(k, v[i])};
		k -= t, v[i] -= t, v[n - 1] += t;
	}

	for (auto& x : v) cout << x << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
