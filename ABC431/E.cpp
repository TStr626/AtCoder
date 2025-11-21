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

enum dir {
	dL = 0,
	dD = 1,
	dR = 2,
	dU = 3
};
struct pos {
	long long i, j;
	dir d;
};
void solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 20000000000;
	cin >> n >> m;
	vector<string> vs(n);
	rep(i, n) {
		cin >> vs[i];
	}
	vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(4, n * m)));
	deque<pos> dq;
	pos p;
	dq.push_front({ 0,0,dL });
	dp[0][0][dL] = 0;
	while (dq.size()) {
		p = dq.front();
		dq.pop_front();
		cur = dp[p.i][p.j][p.d];
		//cout << p.i << ' ' << p.j << ' ' << p.d << ' ' << cur << endl;
		if (vs[p.i][p.j] == 'A') {
			// straight
			switch (p.d) {
				case dL:
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur) {
						dp[p.i][p.j + 1][dL] = cur;
						dq.push_front({ p.i,p.j + 1,dL });
					}
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur + 1) {
						dp[p.i + 1][p.j][dU] = cur + 1;
						dq.push_back({ p.i + 1,p.j,dU });
					}
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur + 1) {
						dp[p.i - 1][p.j][dD] = cur + 1;
						dq.push_back({ p.i - 1,p.j,dD });
					}
					break;
				case dD:
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur) {
						dp[p.i - 1][p.j][dD] = cur;
						dq.push_front({ p.i - 1,p.j,dD });
					}
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
						dp[p.i][p.j + 1][dL] = cur + 1;
						dq.push_back({ p.i ,p.j + 1,dL });
					}
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur + 1) {
						dp[p.i][p.j-1][dR] = cur + 1;
						dq.push_back({ p.i,p.j - 1,dR });
					}
					break;
				case dR:
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur) {
						dp[p.i][p.j - 1][dR] = cur;
						dq.push_front({ p.i,p.j - 1,dR });
					}
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur + 1) {
						dp[p.i + 1][p.j][dU] = cur + 1;
						dq.push_back({ p.i + 1,p.j,dU });
					}
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur + 1) {
						dp[p.i - 1][p.j][dD] = cur + 1;
						dq.push_back({ p.i - 1,p.j,dD });
					}
					break;
				case dU:
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur) {
						dp[p.i + 1][p.j][dU] = cur;
						dq.push_front({ p.i + 1,p.j,dU });
					}
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
						dp[p.i][p.j + 1][dL] = cur + 1;
						dq.push_back({ p.i,p.j + 1,dL });
					}
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur + 1) {
						dp[p.i][p.j - 1][dR] = cur + 1;
						dq.push_back({ p.i,p.j - 1,dR });
					}
					break;
			}
		}
		else if (vs[p.i][p.j] == 'B') {
			// backslash
			switch (p.d) {
				case dL:
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
						dp[p.i][p.j + 1][dL] = cur + 1;
						dq.push_back({ p.i,p.j + 1,dL });
					}
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur) {
						dp[p.i + 1][p.j][dU] = cur;
						dq.push_front({ p.i + 1,p.j,dU });
					}
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur + 1) {
						dp[p.i - 1][p.j][dD] = cur + 1;
						dq.push_back({ p.i - 1,p.j,dD });
					}
					break;
				case dD:
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur+1) {
						dp[p.i - 1][p.j][dD] = cur+1;
						dq.push_back({ p.i - 1,p.j,dD });
					}
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
						dp[p.i][p.j + 1][dL] = cur + 1;
						dq.push_back({ p.i,p.j + 1,dL });
					}
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur) {
						dp[p.i][p.j - 1][dR] = cur;
						dq.push_front({ p.i,p.j - 1,dR });
					}
					break;
				case dR:
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur+1) {
						dp[p.i][p.j - 1][dR] = cur+1;
						dq.push_back({ p.i,p.j - 1,dR });
					}
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur + 1) {
						dp[p.i + 1][p.j][dU] = cur + 1;
						dq.push_back({ p.i + 1,p.j,dU });
					}
					if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur) {
						dp[p.i - 1][p.j][dD] = cur;
						dq.push_front({ p.i - 1,p.j,dD });
					}
					break;
				case dU:
					if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur+1) {
						dp[p.i + 1][p.j][dU] = cur+1;
						dq.push_back({ p.i + 1,p.j,dU });
					}
					if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur) {
						dp[p.i][p.j + 1][dL] = cur;
						dq.push_front({ p.i,p.j + 1,dL });
					}
					if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur + 1) {
						dp[p.i][p.j - 1][dR] = cur + 1;
						dq.push_back({ p.i,p.j - 1,dR });
					}
					break;
			}
		}
		else {
			// slash
			switch (p.d) {
			case dL:
				if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
					dp[p.i][p.j + 1][dL] = cur + 1;
					dq.push_back({ p.i,p.j + 1,dL });
				}
				if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur +1) {
					dp[p.i + 1][p.j][dU] = cur+1;
					dq.push_back({ p.i + 1,p.j,dU });
				}
				if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur) {
					dp[p.i - 1][p.j][dD] = cur;
					dq.push_front({ p.i - 1,p.j,dD });
				}
				break;
			case dD:
				if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur + 1) {
					dp[p.i - 1][p.j][dD] = cur + 1;
					dq.push_back({ p.i - 1,p.j,dD });
				}
				if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur) {
					dp[p.i][p.j + 1][dL] = cur;
					dq.push_front({ p.i,p.j + 1,dL });
				}
				if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur + 1) {
					dp[p.i][p.j - 1][dR] = cur + 1;
					dq.push_back({ p.i,p.j - 1,dR });
				}
				break;
			case dR:
				if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur + 1) {
					dp[p.i][p.j - 1][dR] = cur + 1;
					dq.push_back({ p.i,p.j - 1,dR });
				}
				if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur) {
					dp[p.i + 1][p.j][dU] = cur;
					dq.push_front({ p.i + 1,p.j,dU });
				}
				if (p.i - 1 >= 0 && dp[p.i - 1][p.j][dD] > cur + 1) {
					dp[p.i - 1][p.j][dD] = cur + 1;
					dq.push_back({ p.i - 1,p.j,dD });
				}
				break;
			case dU:
				if (p.i + 1 < n && dp[p.i + 1][p.j][dU] > cur + 1) {
					dp[p.i + 1][p.j][dU] = cur + 1;
					dq.push_back({ p.i + 1,p.j,dU });
				}
				if (p.j + 1 < m && dp[p.i][p.j + 1][dL] > cur + 1) {
					dp[p.i][p.j + 1][dL] = cur + 1;
					dq.push_back({ p.i,p.j + 1,dL });
				}
				if (p.j - 1 >= 0 && dp[p.i][p.j - 1][dR] > cur) {
					dp[p.i][p.j - 1][dR] = cur;
					dq.push_front({ p.i,p.j - 1,dR });
				}
				break;
			}
		}
	}
	ans = dp[n - 1][m - 1][dL] + (vs[n - 1][m - 1] != 'A');
	ans = min(ans, dp[n - 1][m - 1][dU] + (vs[n - 1][m - 1] != 'B'));
	cout << ans << endl;
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}