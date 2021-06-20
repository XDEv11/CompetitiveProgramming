#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (auto& [b, a] : v) cin >> a >> b;

	sort(v.begin(), v.end());

	long long cnt{0};
	for (auto& [b, a] : v) cnt += a;

	long long ans{2 * cnt}, lst{0};
	for (auto& [b, a] : v) {
		if (b >= cnt) break;

		lst = max(lst, b);
		ans -= min(lst + a, cnt) - lst;
		lst = min(lst + a, cnt);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
