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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	long long r, c;
	map<long long, set<long long>> mr, mc;
	cin >> h >> w >> x >> y >> n;
	x--; y--;
	rep(i, n) {
		cin >> r >> c;
		r--; c--;
		mr[r].insert(c);
		mc[c].insert(r);
	}

	long long queue;
	char d;
	cin >> queue;
	auto itr = mr[0].begin();
	r = x; c = y;
	while (queue--) {
		cin >> d >> cur;
		if (d == 'L') {
			if (cur > c) {
				cur = c;
			}
			if (mr[r].size() > 0) {
				itr = mr[r].lower_bound(c);
				if (itr == mr[r].begin()) {
					res = 0;
				}
				else {
					itr--;
					res = *itr + 1;
				}
				cur = min(cur, c - res);
			}
			c -= cur;
		}
		else if (d == 'R') {
			if (cur + c > w - 1) {
				cur = (w - 1) - c;
			}
			if (mr[r].size() > 0) {
				itr = mr[r].upper_bound(c);
				if (itr == mr[r].end()) {
					res = w - 1;
				}
				else {
					res = *itr - 1;
				}
				cur = min(cur, res - c);
			}
			c += cur;
		}
		else if (d == 'U') {
			if (cur > r) {
				cur = r;
			}
			if (mc[c].size() > 0) {
				itr = mc[c].lower_bound(r);
				if (itr == mc[c].begin()) {
					res = 0;
				}
				else {
					itr--;
					res = *itr + 1;
				}
				cur = min(cur, r - res);
			}
			r -= cur;
		}
		else if (d == 'D') {
			if (cur + r > h - 1) {
				cur = (h - 1) - r;
			}
			if (mc[c].size() > 0) {
				itr = mc[c].upper_bound(r);
				if (itr == mc[c].end()) {
					res = h - 1;
				}
				else {
					res = *itr - 1;
				}
				cur = min(cur, res - r);
			}
			r += cur;
		}

		cout << r + 1 << ' ' << c + 1 << endl;
	}

}