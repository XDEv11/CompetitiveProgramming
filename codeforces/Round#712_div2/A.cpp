#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;

	if (all_of(s.begin(), s.end(), [](const char& c){return c == 'a';}))
		return cout << "NO\n", []{}();

	cout << "YES\n";
	s += 'a';
	bool p{true};
	for (int i{0}; i < s.size() / 2; ++i)
		if (s[i] != s[s.size() - 1 - i]) p = false;
	if (!p) cout << s << '\n';
	else s.pop_back(), cout << 'a' << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
