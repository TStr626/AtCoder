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

struct bomb {
	long long p;
	long long x;
	long long y;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<bomb>> b(10);
	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			if (s[i][j] >= '1' && s[i][j] <= '9') {
				cur = s[i][j] - '0';
				b[cur].push_back({ cur,i,j });
			}
		}
	}

	rep(k, 10) {
		for (auto a : b[k]) {
			rep(i, h) {
				rep(j, w) {
					if (abs(i - a.x) + abs(j - a.y) <= a.p) {
						s[i][j] = '.';
					}
				}
			}
		}
	}
	rep(i, h) {
		cout << s[i] << endl;
	}
	
}