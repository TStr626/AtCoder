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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	for(i = n - 2; i >= 0; i--) {
		if (p[i] > p[i + 1]) {
			break;
		}
	}
	cur = -1; res = -1;
	for (j = i + 1; j < n; j++) {
		if (p[i] < p[j]) {
			continue;
		}
		if (cur < p[j]) {
			cur = p[j];
			res = j;
		}
	}
	swap(p[i], p[res]);
	sort(p.begin() + i + 1, p.end());
	reverse(p.begin() + i + 1, p.end());
	rep(i, n) {
		if (i > 0) cout << ' ';
		cout << p[i] + 1;
	}
	cout << endl;
}