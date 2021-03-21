#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n == 1 && v[0] == 1) return cout << "1 1\n", []{}();

	vector<int> L(n); iota(L.begin(), L.end(), -1), L[0] = n - 1;
	vector<int> R(n); iota(R.begin(), R.end(), 1), R[n - 1] = 0;

	vector<int> ans{};
	queue<int> qu{};
	for (int i{0}; i < n; ++i) {
		int next{(i + 1) % n};
		if (gcd(v[i], v[next]) == 1) {
			ans.push_back(next); // delete next

			R[i] = R[next];
			L[R[i]] = i;
			L[next] = R[next] = -1;
			qu.push(R[i]);
			++i; // avoid continuing
		}
	}

	int last{-1};
	while (!qu.empty()) {
		int i{qu.front()}; qu.pop();
		int prev{L[i]};
		if (prev == last) { // continuing
			qu.push(i);
			last = -1;
			continue;
		}
		last = -1;

		if (gcd(v[prev], v[i]) == 1) {
			last = prev;
			ans.push_back(i); // delete i

			if (R[i] == i) break; // only one left
			R[prev] = R[i];
			L[R[prev]] = prev;
			L[i] = R[i] = -1;
			qu.push(R[prev]);
		}
	}

	cout << ans.size() << ' ';
	for (auto& x : ans) cout << x + 1 << ' ';
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
