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
#include<random>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

vector<long long> compress(vector<long long> a, long long begin_value) {
	// need <map>,<algorithm>
	long long i, n = a.size();
	map<long long, long long> mp;
	auto b = a;
	sort(b.begin(), b.end());
	long long cur, res;
	res = b[0] - 1; cur = begin_value - 1;
	for (i = 0; i < n; i++) {
		if (b[i] > res) {
			res = b[i];
			cur++;
			mp[res] = cur;
		}
	}
	for (i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}
	return b;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	long long query;
	cin >> n;
	vector<long long> a(n), b(n), c(2 * n), d;
	mt19937_64 mt(1234567);
	rep(i, n) {
		cin >> c[i];
	}
	rep(i, n) {
		cin >> c[n + i];
	}
	d = compress(c, 0);
	rep(i, n) {
		a[i] = d[i];
	}
	rep(i, n) {
		b[i] = d[n + i];
	}
	
	vector<long long> nhash(2 * n);
	rep(i, 2 * n) {
		nhash[i] = mt();
	}
	set<long long> ast, bst;
	vector<long long> ahash(n + 1, 0), bhash(n + 1, 0);
	rep(i, n) {
		if (ast.count(a[i]) == 0) {
			ast.insert(a[i]);
			ahash[i + 1] = ahash[i] ^ nhash[a[i]];
		}
		else {
			ahash[i + 1] = ahash[i];
		}
	}
	rep(i, n) {
		if (bst.count(b[i]) == 0) {
			bst.insert(b[i]);
			bhash[i + 1] = bhash[i] ^ nhash[b[i]];
		}
		else {
			bhash[i + 1] = bhash[i];
		}
	}
	
	cin >> query;
	while (query--) {
		cin >> x >> y;
		if (ahash[x] == bhash[y]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

}
