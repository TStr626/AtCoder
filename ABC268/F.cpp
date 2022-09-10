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

struct unit {
	long long xcount = 0;
	long long numtotal = 0;
	long long score = 0;
};
bool operator<(unit a, unit b) {
	if (a.xcount * b.numtotal > b.xcount * a.numtotal) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	vector<unit> u(n);
	rep(i, n) {
		rep(j, s[i].size()) {
			if (s[i][j] == 'X') {
				u[i].xcount++;
			}
			else {
				cur = s[i][j] - '0';
				u[i].numtotal += cur;
				u[i].score += u[i].xcount * cur;
			}
		}
	}
	sort(u.begin(), u.end());
	ans = 0; cur = 0;
	rep(i, n) {
		//cout << u[i].numtotal << ' ' << u[i].score << ' ' << u[i].xcount << endl;
		ans += u[i].score;
		ans += cur * u[i].numtotal;
		cur += u[i].xcount;
	}
	cout << ans << endl;
}