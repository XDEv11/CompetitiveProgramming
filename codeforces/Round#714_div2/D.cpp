#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	long long p;
	cin >> n >> p;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0}, mn{v[0]};
	for (int i{1}; i < n; ++i) {
		if ((v[i] >= mn && v[i] % mn) || (v[i] < mn && mn % v[i])) {
			mn = v[i], ans += p;
		} else {
			mn = min(mn, v[i]), ans += min(p, mn);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
