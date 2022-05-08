#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)
struct pos {
	long long x;
	long long y;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<pos> p(2 * n);
	// expand area 4 times
	// remenber all area 2 times-ed 
	rep(i, n) {
		cin >> p[i].x >> p[i].y;
		p[i].x *= 2;
		p[i].y *= 2;
		p[i + n] = p[i];
	}
	// target area
	res = 0;
	rep(i, n) {
		res += (p[i].x * p[i + 1].y - p[i + 1].x * p[i].y);
	}
	res /= 4;
	//cout << res << endl;
	
	// area check
	cur = 0; ans = res;
	j = 0;
	rep(i, n) {
		while (cur < res) {
			cur += ((p[j].x - p[i].x) * (p[j + 1].y - p[i].y) - (p[j + 1].x - p[i].x) * (p[j].y - p[i].y));
			ans = min(ans, abs(cur - res));
			j++;
			//cout << cur << endl;
		}
		cur -= ((p[i].x - p[j].x) * (p[i + 1].y - p[j].y) - (p[i + 1].x - p[j].x) * (p[i].y - p[j].y));
		ans = min(ans, abs(cur - res));
	}
	cout << ans << endl;
}
