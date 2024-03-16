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

struct rect {
	long long h;
	long long w;
};
bool check(long long h, long long w, vector<long long>& p,vector<rect>&r,long long c, long long b) {
	vector<vector<bool>> f(h, vector<bool>(w, 0));
	int t, i, j, x, y, k;
	bool jud, res;
	rep(t, c) {
		res = 0;
		k = p[t];
		//cout << k << ' ';
		rep(i, h) {
			rep(j, w) {
				if (res) {
					break;
				}
				if (f[i][j] == 1) {
					continue;
				}
				//cout << i << j << ' ' << r[k].w << r[k].h << endl;
				if (b & (1 << t)) {
					if ((i + r[k].w > h) || (j + r[k].h > w)) {
						return false;
					}
					else {
						res = 1;
						rep(x, r[k].w) {
							rep(y, r[k].h) {
								if (f[i + x][j + y] == 1) {
									return false;
								}
								f[i + x][j + y] = 1;
							}
						}
					}
				}
				else {
					if ((i + r[k].h > h) || (j + r[k].w > w)) {
						return false;
					}
					else {
						res = 1;
						rep(x, r[k].h) {
							rep(y, r[k].w) {
								if (f[i + x][j + y] == 1) {
									return false;
								}
								f[i + x][j + y] = 1;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> h >> w;
	vector<rect> r(n);
	rep(i, n) {
		cin >> r[i].h >> r[i].w;
	}
	vector<long long> p(n);
	long long b;
	rep(i, n) {
		p[i] = i;
	}
	do {
		cur = 0;
		rep(i, n) {
			cur += r[p[i]].h * r[p[i]].w;
			if (cur == h * w) {
				/*
				rep(j, i + 1) {
					cout << p[j] << ' ';
				}
				*/
				rep(b, (1 << (i+1))) {
					if (!check(h, w, p, r, (i + 1), b)) {
						continue;
					}
					/*
					rep(j, i + 1) {
						cout << p[j] << ' ';
					}
					cout << endl;
					cout << b << endl;
					*/
					yes();
					return 0;
				}
				//cout << b << endl;
			}
		}
	} while (next_permutation(p.begin(), p.end()));
	no();
}