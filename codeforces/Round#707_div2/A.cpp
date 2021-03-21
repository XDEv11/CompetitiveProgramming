#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), tm(n + 1);
	b[0] = 0;
	for (int i{1}; i <= n; ++i) cin >> a[i] >> b[i];
	for (int i{1}; i <= n; ++i) cin >> tm[i];

	int t{0};
	for (int i{1}; i < n; ++i) {
		t += a[i] - b[i - 1] + tm[i];
		t += (b[i] - a[i] + 1) / 2;
		t = max(t, b[i]);
	}

	cout << t + (a[n] - b[n - 1] + tm[n]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
