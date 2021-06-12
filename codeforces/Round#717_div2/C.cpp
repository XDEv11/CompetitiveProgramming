#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int g{0};
	for (auto& x : v) g = gcd(g, x);
	for (auto& x : v) x /= g;

	int s{0};
	for (auto& x : v) s += x;

	vector<bool> t(s + 1, false);
	t[0] = true;
	for (auto& x : v) {
		for (int i{s}; i >= 0; --i)
			if (t[i]) t[i + x] = true;
	}

	if ((s & 1) || (t[s / 2] == false)) cout << "0\n"s;
	else {
		cout << "1\n"s;
		for (int i{0}; i < n; ++i)
			if (v[i] & 1) return cout << i + 1 << '\n', []{}();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
