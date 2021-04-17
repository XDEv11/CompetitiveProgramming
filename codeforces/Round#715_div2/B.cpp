#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	auto check = [](const vector<char>& v) {
		int cntT{0}, cntM{0};
		for (auto& x : v) {
			if (x == 'T') ++cntT;
			else if (x == 'M') {
				if (!cntT) return false;
				--cntT;
				++cntM;
			}
		}
		return cntT == cntM;
	};

	if (check(v) && (reverse(v.begin(), v.end()), check(v))) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
