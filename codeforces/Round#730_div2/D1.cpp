#include <iostream>
#include <cstdlib> // exit()

using namespace std;

static bool guess(int y) {
	cout << y << endl;
	int r;
	cin >> r;
	if (r == -1) exit(EXIT_FAILURE);
	return r == 1;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int c{0};
	for (int i{0}; i < n; ++i) {
		if (guess(i ^ c)) return ;
		c ^= (i ^ c);
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
