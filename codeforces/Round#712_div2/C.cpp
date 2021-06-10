#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) {
		char c;
		cin >> c;
		x = (c == '1');
	}

	int cnt0{count(v.begin(), v.end(), 0)};
	if (v[0] != 1 || v[n - 1] != 1 || cnt0 & 1) return cout << "NO\n"s, []{}();

	string a(n, '-'), b(n, '-');
	a[0] = b[0] = '(';
	a[n - 1] = b[n - 1] = ')';
	int cnt{0}, turn{1};
	for (int i{1}; i < n - 1; ++i) {
		if (v[i] == 1) {
			++cnt;
			a[i] = b[i] = (cnt <= (n - cnt0 - 2) / 2 ? '(' : ')');
		} else {
			turn ? (a[i] = '(', b[i] = ')') : (a[i] = ')', b[i] = '(');
			turn ^= 1;
		}
	}
	cout << "YES\n"s;
   	cout << a << '\n';
   	cout << b << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
