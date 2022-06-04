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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	cin >> n >> k;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	vector<vector<long long>> b(k, vector<long long>(0));
	rep(i, n) {
		b[i % k].push_back(a[i]);
	}

	rep(j, k) {
		sort(b[j].begin(), b[j].end());
	}

	sort(a.begin(), a.end());

	jud = 1;
	rep(i, n) {
		if (a[i] != b[i % k][i / k]) {
			jud = 0;
		}
	}
	cout << (jud ? "Yes" : "No") << endl;
}
