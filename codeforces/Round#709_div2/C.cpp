#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m);
	for (int i{0}; i < m; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int f;
			cin >> f, --f;
			v[i].push_back(f);
		}
	}

	vector<int> cnt(n, 0);
	for (int i{0}; i < m; ++i)
		if (v[i].size() == 1) ++cnt[v[i][0]];
	if (*max_element(cnt.begin(), cnt.end()) > (m + 1) / 2)
		return cout << "NO\n", []{}();

	cout << "YES\n";
	for (int i{0}; i < m; ++i) {
		if (v[i].size() == 1) cout << v[i][0] + 1;
		else {
			for (auto& f : v[i])
				if (cnt[f] + 1 <= (m + 1) / 2) {
					++cnt[f];
					cout << f + 1;
					break;
				}
		}
		cout << ' ';
	}
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
