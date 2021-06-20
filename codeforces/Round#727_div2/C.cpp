#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
	int n;
	long long k, d;
	cin >> n >> k >> d;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	priority_queue<long long, vector<long long>, greater<long long>> pq{};
	for (int i{0}; i + 1 < n; ++i) {
		if (v[i + 1] - v[i] > d)
			pq.push((v[i + 1] - v[i] - 1) / d);
	}

	while (!pq.empty() && k >= pq.top()) {
		k -= pq.top(), pq.pop();
	}

	cout << 1 + pq.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
