#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (2 * k >= n) return cout << "NO\n", []{}();
	for (int i{0}; i < k; ++i)
		if (v[i] != v[n - 1 - i]) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
