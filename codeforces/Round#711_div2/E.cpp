#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

static inline bool ask(int u, int v) {
	cout << "? "s << u + 1 << ' ' << v + 1 << endl;
	string ret;
	return cin >> ret, ret == "Yes"s;
}

static inline void ans(int a, int b) {
	cout << "! "s << a + 1 << ' ' << b + 1 << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> k(n);
	for (auto& x : k) cin >> x;
	
	vector<pair<int, pair<int, int>>> v{};
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			if (k[i] <= k[j]) v.emplace_back(k[j] - k[i], make_pair(i, j));
			else v.emplace_back(k[i] - k[j], make_pair(j, i));
		}
	sort(v.rbegin(), v.rend());

	for (auto& [_, p] : v) {
		auto& [a, b]{p};
		if (ask(b, a)) return ans(b, a);
	}
	ans(-1, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
