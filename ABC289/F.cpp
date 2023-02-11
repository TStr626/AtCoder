#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}
struct pos {
	long long x;
	long long y;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	pos s, t;
	cin >> s.x >> s.y >> t.x >> t.y;
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<long long> ansx, ansy;
	// x check
	if ((s.x % 2 != t.x % 2) || (s.y % 2 != t.y % 2)) {
		no();
		return 0;
	}

	if (a == b && c == d) {
		if (s.x == t.x && s.y == t.y) {
			yes();
			return 0;
		}
		if (2 * a - s.x == t.x && 2 * c - s.y == t.y) {
			yes();
			cout << a << ' ' << c << endl;
			return 0;
		}
		else {
			no();
			return 0;
		}
	}

	// parity check
	jud = 0;
	if (a == b) {
		jud |= 1;
		if (s.x == t.x) {
			// pass
		}
		else if (2 * a - s.x == t.x) {
			ansx.push_back(a);
		}
		else {
			no();
			return 0;
		}
	}

	if (c == d) {
		jud |= 2;
		if (s.y == t.y) {
			// pass
		}
		else if (2 * c - s.y == t.y) {
			ansy.push_back(c);
		}
		else {
			no();
			return 0;
		}
	}

	if (jud == 3 && (ansx.size() != ansy.size())) {
		no();
		return 0;
	}

	// adjust
	if (jud == 1 && ansx.size() > ansy.size()) {
		ansy.push_back(c);
		s.y = 2 * c - s.y;
		s.x = t.x;
	}
	if (jud == 2 && ansy.size() > ansx.size()) {
		ansx.push_back(a);
		s.x = 2 * a - s.x;
		s.y = t.y;
	}
	while (s.x != t.x) {
		if (s.x < t.x) {
			ansx.push_back(a);
			ansx.push_back(a + 1);
			ansy.push_back(c);
			ansy.push_back(c);
			s.x += 2;
		}
		if (s.x > t.x) {
			ansx.push_back(a + 1);
			ansx.push_back(a);
			ansy.push_back(c);
			ansy.push_back(c);
			s.x -= 2;
		}
	}
	while (s.y != t.y) {
		if (s.y < t.y) {
			ansx.push_back(a);
			ansx.push_back(a);
			ansy.push_back(c);
			ansy.push_back(c + 1);
			s.y += 2;
		}
		if (s.y > t.y) {
			ansx.push_back(a);
			ansx.push_back(a);
			ansy.push_back(c + 1);
			ansy.push_back(c);
			s.y -= 2;
		}
	}
	yes();
	rep(i, ansx.size()) {
		cout << ansx[i] << ' ' << ansy[i] << endl;
	}
	return 0;
}