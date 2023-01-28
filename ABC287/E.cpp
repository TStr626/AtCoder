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

struct pos {
	string s;
	long long num;
};
bool operator<(pos a, pos b) {
	return a.s < b.s;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000;
	cin >> n;
	vector<pos> p(n);
	vector<long long> l(n - 1, 0);
	rep(i, n) {
		cin >> p[i].s;
		p[i].num = i;
	}
	sort(p.begin(), p.end());
	rep(i, n - 1) {
		rep(j, min(p[i].s.size(), p[i + 1].s.size())) {
			if (p[i].s[j] == p[i + 1].s[j]) {
				l[i]++;
			}
			else {
				break;
			}
		}
	}
	vector<long long> vans(n);
	rep(i, n) {
		cur = p[i].num;
		if (i < n - 1) {
			vans[cur] = max(vans[cur], l[i]);
		}
		if (i > 0) {
			vans[cur] = max(vans[cur], l[i - 1]);
		}
	}
	rep(i, n) {
		cout << vans[i] << endl;
	}
}