#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> x(n), y(n);
	for (int i{0}; i < n; ++i) cin >> x[i] >> y[i];

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	cout << (x[n / 2] - x[(n - 1) / 2] + 1) * (y[n / 2] - y[(n - 1) / 2] + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
