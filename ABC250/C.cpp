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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long query;
	cin >> n >> query;
	vector<long long> p(n), pinv(n);
	rep(i, n) {
		p[i] = i;
		pinv[i] = i;
	}
	while (query--) {
		cin >> x;
		x--;
		cur = pinv[x];
		if (cur == n - 1) {
			cur--;
			x = p[cur];
		}
		y = p[cur + 1];

		swap(p[cur], p[cur + 1]);
		pinv[y] = cur;
		pinv[x] = cur+1;
	}
	rep(i, n) {
		if (i) cout << ' ';
		cout << p[i] + 1;
	}
	cout << endl;
	/*
	rep(i, n) {
		if (i) cout << ' ';
		cout << pinv[i] + 1;
	}
	cout << endl;
	*/
}