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

	int p{ask(1, n)};
	if (ask(1, p) == p) {
		int l{1}, r{p - 1};
		while (l < r) {
			int m{(l + r) / 2};
			if (ask(m + 1, p) == p) l = m + 1;
			else r = m;
		}
		ans(l);
	} else {
		int l{p + 1}, r{n};
		while (l < r) {
			int m{(l + r) / 2};
			if (ask(p, m) == p) r = m;
			else l = m + 1;
		}
		ans(l);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
