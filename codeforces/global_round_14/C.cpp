#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> h(n);
	for (auto& e : h) cin >> e;

	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) v[i] = {h[i], i};
	sort(v.rbegin(), v.rend());

	using pq_t = pair<int, int>;
	priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
	for (int i{1}; i <= m; ++i) pq.emplace(0, i);

	vector<int> ans(n);
	for (auto& [e, i] : v) {
		auto t{pq.top()}; pq.pop();
		auto& [s, j]{t};
		ans[i] = j, s += e;
		pq.push(t);
	}

	cout << "YES\n"s;
	for (auto& e : ans) cout << e << ' ';
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
