#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n{s.length()};

	vector<int> v1(n, 0);
	for (int i{0}; i < n; ) {
		int j{i};
		for ( ; j < n; ++j)
			if (s[j] == '?' || s[j] == '0' + (j & 1 ? 1 : 0)) ;
			else break;
		for ( ; i < j; ++i) v1[i] = j - i;
		++i;
	}

	vector<int> v2(n, 0);
	for (int i{0}; i < n; ) {
		int j{i};
		for ( ; j < n; ++j)
			if (s[j] == '?' || s[j] == '0' + (j & 1 ? 0 : 1)) ;
			else break;
		for ( ; i < j; ++i) v2[i] = j - i;
		++i;
	}

	long long ans{0};
	for (int i{0}; i < n; ++i)
		ans += max(v1[i], v2[i]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
