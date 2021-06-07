#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	queue<string> qu{};
	qu.emplace();

	while (!qu.empty()) {
		auto t{qu.front()}; qu.pop();
		t += '$';
		for (int i{0}; i < 26; ++i) {
			t.back() = 'a' + i;
			if (search(s.begin(), s.end(), t.begin(), t.end()) == s.end())
				return cout << t << '\n', []{}();
			qu.push(t);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
