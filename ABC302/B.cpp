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
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	vector<long long> dx = { 1,1,1,0,-1,-1,-1,0 }, dy = { 1,0,-1,-1,-1,0,1,1 };
	
	string tg = "snuke";
	long long l;
	rep(i, h) {
		rep(j, w) {
			rep(k, 8) {
				x = i; y = j;
				rep(l, 5) {
					if (x < 0 || x >= h || y < 0 || y >= w) {
						// out of range
						break;
					}
					if (s[x][y] != tg[l]) {
						// wrong word
						break;
					}
					x += dx[k]; y += dy[k];
				}

				if (l == 5) {
					// found
					x = i; y = j;
					rep(l, 5) {
						cout << x + 1 << ' ' << y + 1 << endl;
						x += dx[k]; y += dy[k];
					}
					return 0;
				}
			}
		}
	}
	
}