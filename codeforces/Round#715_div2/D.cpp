#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<vector<char>, 3> v{};
	array<int, 3> c{}; // count 1
	for (int k{0}; k < 3; ++k) {
		v[k].assign(2 * n, '\0');
		for (int i{0}; i < 2 * n; ++i) {
			cin >> v[k][i];
			c[k] += v[k][i] - '0';
		}
	}

	string ans{};
	for (int i{0}; i < 3; ++i)
		for (int j{i + 1}; j < 3; ++j) {
			char m{0};
			if (c[i] >= n && c[j] >= n) m = '1';
			else if (c[i] <= n && c[j] <= n) m = '0';
			if (m) {
				int k{0}, l{0};
				while (true) {
					while (k < 2 * n && v[i][k] != m) ans += v[i][k++];
					while (l < 2 * n && v[j][l] != m) ans += v[j][l++];
					if (k >= 2 * n && l >= 2 * n) break;
					ans += m, ++k, ++l;
				}
				while (ans.size() < 3 * n) ans += m;
				return cout << ans << '\n', []{}();
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
