#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void _modify(vector<pair<char, int>>& t, int tv) {
	if (tv < t.size() / 2) {
		if (t[tv].first == '?')
			t[tv].second = t[tv * 2 + 1].second + t[tv * 2 + 2].second;
		else if (t[tv].first == '0') t[tv].second = t[tv * 2 + 2].second;
		else if (t[tv].first == '1') t[tv].second = t[tv * 2 + 1].second;
	} else {
		if (t[tv].first == '?') t[tv].second = 2;
		else t[tv].second = 1;
	}

	if (tv) _modify(t, (tv - 1) / 2);
}

void modify(vector<pair<char, int>>& t, int tv, char c) {
	t[tv].first = c;
	_modify(t, tv);
}

void solve() {
	int k;
	cin >> k;
	int n{(1 << k) - 1};
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<char, int>> t(n);
	for (int i{0}; i < n; ++i) modify(t, n - 1 - i, v[i]);

	int q;
	cin >> q;
	while (q--) {
		int tv;
		char c;
		cin >> tv >> c, tv = n - tv;
		modify(t, tv, c);

		cout << t[0].second << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
