#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 4> a;
	for (auto& x : a) cin >> x;

	int mx1{distance(a.begin(), max_element(a.begin(), a.end()))};
	a[mx1] = 0;
	int mx2{distance(a.begin(), max_element(a.begin(), a.end()))};

	if (mx1 > mx2) swap(mx1, mx2);

	if ((mx1 == 0 && mx2 == 1) || (mx1 == 2 && mx2 == 3)) cout << "NO\n"s;
	else cout << "YES\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
