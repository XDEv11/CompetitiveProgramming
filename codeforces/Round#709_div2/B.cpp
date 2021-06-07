#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	bool flag{true};
	set<long long> s{};
	for (int i{1}; i < n; ++i) {
		if (v[i] - v[i - 1] != v[1] - v[0]) flag = false;
		s.insert(v[i] - v[i - 1]);
	}
	if (flag) return cout << "0\n", []{}();

	// set size must be greater or equal to 2
	if (s.size() > 2 || *s.begin() >= 0) return cout << "-1\n", []{}();

	long long c{*next(s.begin())}, m{-1 * (*s.begin()) + c};
	if (!(v[0] < m)) return cout << "-1\n", []{}();
	for (int i{1}; i < n; ++i)
		if ((v[i - 1] + c) % m != v[i]) return cout << "-1\n", []{}();

	cout << m << ' ' << c << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
