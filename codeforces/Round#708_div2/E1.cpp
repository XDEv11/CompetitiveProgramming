#include <iostream>
#include <vector>
#include <set>

using namespace std;

constexpr int MAX{10000000};
vector<int> T(MAX + 1);

void build_table() {
	for (int i{1}; i <= MAX; ++i) T[i] = i;
	for (int i{2}; i * i <= MAX; ++i) {
		int ps{i * i};
		for (int j{ps}; j <= MAX; j += ps)
			while (T[j] % ps == 0) T[j] /= ps;
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x, x = T[x];

	int ans{1};

	set<int> s{};
	for (int i{0}; i < n; ++i) {
		if (s.find(v[i]) != s.end()) s.clear(), ++ans;
		s.insert(v[i]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	build_table();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
