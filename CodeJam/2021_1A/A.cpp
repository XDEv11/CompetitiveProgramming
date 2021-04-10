#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static inline bool number_cmp(const string& x, const string& y) {
	if (x.length() != y.length()) return x.length() > y.length();
	else return x > y;
}

static inline int prefix_cmp(const string& x, const string& y) {
	auto len{min(x.length(), y.length())};
	for (size_t i{0}; i < len; ++i)
		if (x[i] > y[i]) return 1; // greater
		else if (x[i] < y[i]) return -1; //smaller
	return 0; // equal
}

static inline size_t grow_to(const string& x, string& y) {
	if (number_cmp(y, x)) return 0;
	auto x_len{x.length()}, y_len{y.length()};

	auto suffix_ok = [&] {
		for (auto i{y_len}; i < x_len; ++i)
			if (x[i] != '9') return true;
		return false;
	};

	auto c{prefix_cmp(x, y)};
	if (c == -1) {
		for (auto i{y_len}; i < x_len; ++i) y += '0';
		return x_len - y_len;
	} else if (c == 0 && suffix_ok()) {
		for (auto i{y_len}; i < x_len; ++i) y += x[i];
		for (auto i{x_len - 1}; ; --i) {
			if (y[i] == '9') y[i] = '0';
			else {
				y[i] += 1;
				break;
			}
		}
		return x_len - y_len;
	} else {
		for (auto i{y_len}; i <= x_len; ++i) y += '0';
		return x_len - y_len + 1;
	}
}

void solve() {
	static int t{0};
	cout << "Case #" << ++t << ": ";
	
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	size_t ans{0};
	for (int i{0}; i + 1 < n; ++i)
		ans += grow_to(v[i], v[i + 1]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
