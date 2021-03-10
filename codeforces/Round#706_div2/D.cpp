#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> L(n, 0), R(n, 0);
	for (int i{1}; i < n; ++i)
		if (v[i] > v[i - 1]) L[i] = L[i - 1] + 1;
	for (int i{n - 2}; i >= 0; --i)
		if (v[i] > v[i + 1]) R[i] = R[i + 1] + 1;

	int mxL{-1}, idxL, mxR{-1}, idxR;
	for (int i{0}; i < n; ++i) {
		if (L[i] > mxL) mxL = L[i], idxL = i;
		if (R[i] > mxR) mxR = R[i], idxR = i;
	}

	for (int i{0}; i < n; ++i) {
		if (L[i] == mxL && i != idxL) return cout << "0\n", []{}();
		if (R[i] == mxR && i != idxR) return cout << "0\n", []{}();
	}

	if (mxL == mxR && idxL == idxR && !(mxL & 1)) cout << "1\n";
	else cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
