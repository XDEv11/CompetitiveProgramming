#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <iterator>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> ans{};

	list<int> rlst{}; // remaining list
	for (int i{0}; i < n; ++i) rlst.push_back(i);
	list<typename decltype(rlst)::iterator> dlst{}; // list going to be deleted
	for (auto it{rlst.begin()}; it != rlst.end(); ++it) {
		auto nxt{next(it) == rlst.end() ? rlst.begin() : next(it)};
		if (gcd(v[*it], v[*nxt]) == 1) dlst.push_back(nxt);
	}

	auto it{dlst.begin()};
	while (!dlst.empty()) {
		// x - y - z
		auto y{*it};
		auto x{prev(*it == rlst.begin() ? rlst.end() : *it)};
		auto z{(next(*it) == rlst.end() ? rlst.begin() : next(*it))};
		
		ans.push_back(*y);
		rlst.erase(y), it = dlst.erase(it); // due to (x, y)
		if (it == dlst.end()) it = dlst.begin();
		if (rlst.empty()) break;

		if (!dlst.empty() && *it == z) it = dlst.erase(it); // if (y, z)
		if (it == dlst.end()) it = dlst.begin();

		if (gcd(v[*x], v[*z]) == 1)
			it = dlst.insert(it, z), it = (next(it) == dlst.end() ? dlst.begin() : next(it)); // if (x, z)
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
