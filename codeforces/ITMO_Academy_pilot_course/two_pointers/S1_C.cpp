#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	long long ans{0};
	int i{0}, j{0};
	while (i < n && j < m) {
		if (a[i] < b[j]) ++i;
		else if (a[i] > b[j]) ++j;
		else {
			++i, ++j;
			long long c1{1}, c2{1};
			while (i < n && a[i] == a[i - 1]) ++i, ++c1;
			while (j < m && b[j] == b[j - 1]) ++j, ++c2;
			ans += c1 * c2;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
