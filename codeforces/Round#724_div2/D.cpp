#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include <limits>
#include <tuple>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	set<int> st{};
	st.insert(numeric_limits<int>::max());
	st.insert(numeric_limits<int>::min());
	auto [med, _]{st.insert(v[0])};
	for (int i{1}; i < n; ++i) {
		if (v[i] == *med || (v[i] > *med && *next(med) >= v[i]) || (v[i] < *med && *prev(med) <= v[i])) {
			tie(med, _) = st.insert(v[i]);
		} else return cout << "NO\n"s, []{}();
	}
	cout << "YES\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
