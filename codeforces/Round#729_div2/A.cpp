#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (auto& x : v) cin >> x;

	if (count_if(v.begin(), v.end(), [](const int& x){return x & 1;}) == n) cout << "Yes\n"s;
	else cout << "No\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
