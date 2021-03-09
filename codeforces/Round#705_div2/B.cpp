#include <iostream>
#include <optional>
#include <iomanip>

using namespace std;

optional<int> mirror(int d) {
	switch (d) {
		case 0 : return 0;
		case 1 : return 1;
		case 2 : return 5;
		case 3 : return nullopt;
		case 4 : return nullopt;
		case 5 : return 2;
		case 6 : return nullopt;
		case 7 : return nullopt;
		case 8 : return 8;
		default : return nullopt;
	}
}

bool mirror_valid(int n, int tot) {
	auto d1{mirror(n % 10)}, d2{mirror(n / 10)};
	if (d1 && d2 && d2.value() + 10 * d1.value() < tot) return true;
	else return false;
}

void solve() {
	int h, m;
	cin >> h >> m;

	int th, tm;
	(cin >> th).ignore() >> tm;

	while (!(mirror_valid(th, m) && mirror_valid(tm, h))) {
		if (tm == m - 1) tm =0, th = (th + 1) % h;
		else tm += 1;
	}

	cout << setfill('0') << setw(2) << th << ":" << setw(2) << tm << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
