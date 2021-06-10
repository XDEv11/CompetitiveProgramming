#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fi first
#define se second

void solve() {
	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (auto& [a, c] : v) cin >> a >> c;

	sort(v.begin(), v.end());

	long long ans{0};
	for (auto& [a, c] : v) ans += c;

	long long mx{v[0].fi + v[0].se};
	for (int i{1}; i < n; ++i)
		if (v[i].fi + v[i].se > mx) {
			ans += max(0ll, v[i].fi - mx);
			mx = v[i].fi + v[i].se;
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
