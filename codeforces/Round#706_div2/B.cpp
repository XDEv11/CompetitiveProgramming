#include <iostream>
#include <set>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> s{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	if (*s.begin() == 0 && *prev(s.end()) == n - 1) return cout << n + k << '\n', []{}();

	if (k) {
		int mex{0};
		while (s.find(mex) != s.end()) ++mex;
		s.insert((mex + *prev(s.end()) + 1) / 2);
	}
	cout << s.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
