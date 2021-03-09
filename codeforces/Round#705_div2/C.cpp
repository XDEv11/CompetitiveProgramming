#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (auto& c : v) cin >> c;

	if (n % k) return cout << "-1\n", []{}();

	array<int, 26> cnt{};
	for (auto& c : v) ++cnt[c - 'a'];

	bool f{true};
	for (auto& x : cnt) f = f && !(x % k);
	if (f) {
		for (auto& c : v) cout << c;
		return cout << '\n', []{}();
	}

	for (int i{n - 1}; i >= 0; --i) {
		--cnt[v[i] - 'a'];
		int need{0}, mx;
		for (int c{0}; c < 26; ++c)
			if (cnt[c] % k) need += k - (cnt[c] % k), mx = c;

		if ((v[i] < 'z' && need < n - i) || (v[i] - 'a' + 1 <= mx && need == n - i)) {
			if (need < n - i) ++v[i], ++cnt[v[i] - 'a']; // v[i]
			else {
				for (int c{v[i] - 'a' + 1}; c < 26; ++c)
					if (cnt[c] % k) {
						v[i] = 'a' + c;
						++cnt[c];
						break;
					}
			}

			int j{n - 1}; // v[i+1:n)
			for (int c{25}; c >= 0; --c) {
				while (cnt[c] % k) v[j--] = 'a' + c, ++cnt[c];
			}
			while (j > i) v[j--] = 'a';

			for (auto& c : v) cout << c;
			return cout << '\n', []{}();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
