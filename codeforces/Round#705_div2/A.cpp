#include <iostream>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	cout << n - (k + 1) / 2 << '\n';

	for (int i{(k + 1) / 2}; i <= n; ++i)
		if (i != k) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
