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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long ha, wa, hb, wb, hc, wc;
	cin >> ha >> wa;
	vector<string> a(ha);
	rep(i, ha) {
		cin >> a[i];
	}
	cin >> hb >> wb;
	vector<string> b(hb);
	rep(i, hb) {
		cin >> b[i];
	}
	cin >> hc >> wc;
	vector<string> c(hc);
	rep(i, hc) {
		cin >> c[i];
	}
	
	// remove edge of a
	long long u, d, l, r;
	u = ha - 1; d = 0; l = wa - 1; r = 0;
	rep(i, ha) {
		rep(j, wa) {
			if (a[i][j] == '#') {
				u = min(u, i);
				d = max(d, i);
				l = min(l, j);
				r = max(r, j);
			}
		}
	}
	vector<string> va(0);
	for (i = u; i <= d; i++) {
		va.push_back(a[i].substr(l, r - l + 1));
	}
	ha = va.size();
	wa = va[0].size();

	// remove edge of b
	u = hb - 1; d = 0; l = wb - 1; r = 0;
	rep(i, hb) {
		rep(j, wb) {
			if (b[i][j] == '#') {
				u = min(u, i);
				d = max(d, i);
				l = min(l, j);
				r = max(r, j);
			}
		}
	}
	vector<string> vb(0);
	for (i = u; i <= d; i++) {
		vb.push_back(b[i].substr(l, r - l + 1));
	}
	hb = vb.size();
	wb = vb[0].size();

	for (i = 0; i + ha <= hc; i++) {
		for (j = 0; j + wa <= wc; j++) {
			for (k = 0; k + hb <= hc; k++) {
				for (l = 0; l + wb <= wc; l++) {
					jud = 1;
					rep(m, hc) {
						rep(n, wc) {
							cur = (c[m][n] == '#');
							res = 0;
							res |= (i <= m) && (m < i + ha) && (j <= n) && (n < j + wa) && (va[m - i][n - j] == '#');
							res |= (k <= m) && (m < k + hb) && (l <= n) && (n < l + wb) && (vb[m - k][n - l] == '#');
							if (cur != res) {
								jud = 0;
							}
						}
					}
					if (jud) {
						yes();
						return 0;
					}
				}
			}
		}
	}
	no();
	
}