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
	long long n, m, i, j, k, h, w, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> x(n), c(n);
	rep(i, n) {
		cin >> x[i];
		x[i]--;
	}
	rep(i, n) {
		cin >> c[i];
	}

	vector<int> check(n, 1);
	vector<int> loop(0);
	long long fin;

	ans = 0;
	for (i = 0; i < n; i++) {
		if (check[i] == 0) continue;
		res = i;
		loop.push_back(res);
		while (check[res] == 1) {
			check[res] = 2;
			res = x[res];
			loop.push_back(res);
		}

		if (check[res] == 2) {
			fin = res;
			cur = c[fin];
			res = x[res];
			while (res != fin) {
				cur = min(cur, c[res]);
				res = x[res];
			}
			ans += cur;
		}

		while (loop.size()) {
			res = loop[loop.size() - 1];
			check[res] = 0;
			loop.pop_back();
		}
	}
	cout << ans << endl;

}