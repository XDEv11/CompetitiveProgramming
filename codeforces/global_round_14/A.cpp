#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	if (accumulate(v.begin(), v.end(), 0) == x) return cout << "NO\n"s, []{}();

	int s{0};
	for (int i{0}; i < n - 1; ++i) {
		s += v[i];
		if (s == x) {
			swap(v[i], v[i + 1]);
			break;
		}
	}
	cout << "YES\n"s;
	for (auto& e : v) cout << e << ' ';
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
