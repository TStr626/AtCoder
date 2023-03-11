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

void solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	set<long long> st;
	// base check
	for (x = 2; x <= 100; x++) {
		cur = n; jud = 1;
		while (cur) {
			if (cur % x > 1) {
				jud = 0;
				break;
			}
			cur /= x;
		}
		if (jud) {
			st.insert(x);
		}
	}
	// possible in 9 digit ?
	long long b, lo, hi, mid;
	for (b = 2; b <= (1 << 9); b++) {
		lo = 2; hi = 1000000000000000001;
		while (hi - lo > 1) {
			mid = (hi + lo) / 2;

			cur = b; res = 0; jud = 1;
			while (cur) {
				if (cur & 1) {
					res += jud;
				}
				cur >>= 1;
				if (cur && (n / jud) < mid) {
					res = n + 1;
					break;
				}
				jud *= mid;
			}
			if (res <= n) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}

		cur = b; res = 0; jud = 1;
		while (cur) {
			if (cur & 1) {
				res += jud;
			}
			cur >>= 1;
			if (cur && (n / jud) < lo) {
				res = n + 1;
				break;
			}
			jud *= lo;
		}

		if (res == n) {
			st.insert(lo);
		}
	}
	cout << st.size() << endl;

}
int main() {
	long long test;
	cin >> test;
	while (test--) {
		solve();
	}
}