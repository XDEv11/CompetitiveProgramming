#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	int n;
	long long p;
	cin >> n >> p;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	using pq_t = pair<long long, int>;
	priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
	for (int i{0}; i < n; ++i) pq.emplace(v[i], i);

	vector<bool> cn(n - 1, false); // if i and i + 1 is connected
	while (!pq.empty()) {
		auto [g, i]{pq.top()}; pq.pop();
		if (g >= p) break;

		for (int j{i - 1}; j >= 0; --j) {
			if (cn[j] || v[j] % g) break;
			ans += g;
			cn[j] = true; // j is connected to i, i.e, connected to j + 1
		}
		for (int j{i + 1}; j < n; ++j) {
			if (cn[j - 1] || v[j] % g) break;
			ans += g;
			cn[j - 1] = true; // j is connected to i, i.e, connected to j - 1
		}
	}

	for (int i{0}; i < n - 1; ++i)
		if (!cn[i]) ans += p;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
