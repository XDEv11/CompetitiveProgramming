#include <iostream>

using namespace std;

int ask(int l, int r) {
	if (l >= r) return -1;

	cout << "? " << l << " " << r << endl;
	int res;
	cin >> res;
	return res;
}

void ans(int p) {
	cout << "! " << p << endl;
}

void solve() {
	int n;
	cin >> n;

	int l{1}, r{n};
	while (l < r) {
		int m{(l + r) / 2};

		int p{ask(l, r)};
		if (p <= m) {
			if (ask(l, m) == p) r = m;
			else l = m + 1;
		} else {
			if (ask(m + 1, r) == p) l = m + 1;
			else r = m;
		}
	}
	ans(l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
