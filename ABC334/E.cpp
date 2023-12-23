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

long long powmod(long long n, long long m, long long mod) {
	// mod>0
	long long i, ans, cur, res;
	if (n % mod == 0) {
		return 0;
	}
	ans = 1; cur = n % mod; res = m;
	while (res > 0) {
		if (res % 2 == 1) {
			ans = (ans * cur) % mod;
		}
		cur = (cur * cur) % mod;
		res /= 2;
	}
	return ans;
}

long long invmod(long long n, long long mod) {
	// mod must be prime
	// n%mod > 0
	// need "powmod"
	return powmod(n, mod - 2, mod);
}

struct pos {
	long long x;
	long long y;
};
vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
void coloring(vector<string> s, vector<vector<long long>>& c, long long& cnt) {
	cnt = 0;
	queue<pos> qu;
	pos p;
	long long h = s.size(), w = s[0].size(), i, j, k;
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '.') {
				continue;
			}

			cnt++;
			qu.push({ i,j });
			s[i][j] = '.';
			while (qu.size()) {
				p = qu.front();
				qu.pop();
				c[p.x][p.y] = cnt;
				for (k = 0; k < 4; k++) {
					if (p.x + dx[k] < 0 || p.x + dx[k] >= h || p.y + dy[k] < 0 || p.y + dy[k] >= w) {
						continue;
					}
					if (s[p.x + dx[k]][p.y + dy[k]] == '.') {
						continue;
					}
					qu.push({ p.x + dx[k],p.y + dy[k] });
					s[p.x + dx[k]][p.y + dy[k]] = '.';
				}
			}
		}
	}
	return;
}

long long judge(vector<vector<long long>>& c, pos p) {
	long long k, x, y, h = c.size(), w = c[0].size();
	set<long long> st;
	rep(k, 4) {
		x = p.x + dx[k]; y = p.y + dy[k];
		if (x < 0 || y < 0 || x >= h || y >= w) {
			continue;
		}
		if (c[x][y] == 0) {
			continue;
		}
		st.insert(c[x][y]);
	}
	return 1 - st.size();
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> h >> w;
	vector<string> s(h);
	res = 0;
	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			if (s[i][j] == '.') {
				res++;
			}
		}
	}
	vector<vector<long long>> c(h, vector<long long>(w));
	coloring(s, c, ans);
	cur = 0;
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '#') {
				continue;
			}
			cur += judge(c, { i,j });
		}
	}
	//cout << ans << endl;
	//cout << cur << endl;
	//cout << res << endl;
	cur = ((cur + mod) * (invmod(res, mod))) % mod;
	ans = (ans + cur) % mod;
	cout << ans << endl;

}