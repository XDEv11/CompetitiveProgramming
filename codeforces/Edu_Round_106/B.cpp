#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	int i{s.size() - 1};
	while (--i >= 0)
		if (s[i] == '0' && s[i] == s[i + 1]) break;

	while (--i >= 0)
		if (s[i] == '1' && s[i] == s[i + 1]) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
