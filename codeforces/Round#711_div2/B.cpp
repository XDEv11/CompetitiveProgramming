#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, w;
	cin >> n >> w;

	array<int, 21> cnt{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[__builtin_ctz(x)];
	}

	int ans{0};
	while (!all_of(cnt.begin(), cnt.end(), [](int c){return c == 0;})) {
		++ans;
		int t{w};
		for (int i{20}; i >= 0; --i) {
			int d{min(cnt[i], t / (1 << i))};
			cnt[i] -= d, t -= d * (1 << i);
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
