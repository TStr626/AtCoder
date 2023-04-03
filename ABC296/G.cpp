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
long long out(pos a, pos b, pos c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool isOn(pos p, pos a, pos b) {
	// if p is on line a-b
	return p.y * (a.x - b.x) + a.y * (b.x - p.x) + b.y * (p.x - a.x) == 0;
}
void isInside(pos p, vector<pos>& s) {
	int n = s.size();
	int l = 1, r = n, mid;
	pos q = s[0];
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (out(q, p, s[mid]) <= 0) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (l == n - 1) {
		l = n - 2;
	}
	r = l + 1;
	long long v0, v1, v2;
	v0 = out(q, s[l], s[r]);
	v1 = out(q, p, s[r]);
	v2 = out(q, s[l], p);
	if (v0 < 0) {
		v1 *= -1;
		v2 *= -1;
	}

	
	// is inside?
	if (0 <= v1 && 0 <= v2 && v1 + v2 <= v0) {
		// is on boundary?
		if (isOn(p, s[l], s[r])) {
			cout << "ON" << endl;
			return;
		}
		if (l == 1 && isOn(p, s[0], s[l])) {
			cout << "ON" << endl;
			return;
		}
		if (r == n - 1 && isOn(p, s[0], s[r])) {
			cout << "ON" << endl;
			return;
		}
		cout << "IN" << endl;
		return;
	}
	cout << "OUT" << endl;
	return;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<pos> s(n);
	rep(i, n) {
		cin >> s[i].x >> s[i].y;
	}
	cin >> m;
	pos p;
	rep(j, m) {
		cin >> p.x >> p.y;
		isInside(p, s);
	}
}