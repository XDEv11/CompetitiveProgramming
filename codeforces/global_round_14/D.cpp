#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> lcnt(n + 1, 0), rcnt(n + 1, 0);
	for (int i{0}; i < l; ++i) {
		int c;
		cin >> c;
		lcnt[c] += 1;
	}
	for (int i{0}; i < r; ++i) {
		int c;
		cin >> c;
		rcnt[c] += 1;
	}

	int ans{0}, left{n};

	for (int c{1}; c <= n; ++c) { // already matched
		int t{min(lcnt[c], rcnt[c])};
		lcnt[c] -= t;
		rcnt[c] -= t;
		left -= 2 * t;
	}

	int d{0};
	if (l > r) {
		d = l - r;
		for (int c{1}; c <= n; ++c) {
			int t{min(d, lcnt[c] - (lcnt[c] & 1))};
			d -= t, lcnt[c] -= t;
			ans += t / 2;
			left -= t;
		}
	} else if (l < r) {
		d = r - l;
		for (int c{1}; c <= n; ++c) {
			int t{min(d, rcnt[c] - (rcnt[c] & 1))};
			d -= t, rcnt[c] -= t;
			ans += t / 2;
			left -= t;
		}
	}
	ans += d / 2;

	ans += left / 2;

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
