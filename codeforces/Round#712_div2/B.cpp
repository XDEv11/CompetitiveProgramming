#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '1');
	}
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		b[i] = (c == '1');
	}

	vector<int> v(n);
	v[0] = (a[0] ? 1 : -1);
	for (int i{1}; i < n; ++i) v[i] = v[i - 1] + (a[i] ? 1 : -1);

	bool f{false};
	for (int i{n - 1}; i >= 0; --i) {
		a[i] ^= f;
		if (a[i] != b[i]) {
			if (v[i]) return cout << "NO\n"s, []{}();
			else f ^= true;
		}
	}
	cout << "YES\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
