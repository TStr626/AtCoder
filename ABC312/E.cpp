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

struct cub {
	long long x1;
	long long x2;
	long long y1;
	long long y2;
	long long z1;
	long long z2;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long z;
	vector<vector<vector<long long>>> a(100, vector<vector<long long>>(100, vector<long long>(100, 0)));
	cin >> n;
	cub c;
	rep(i, n) {
		cin >> c.x1 >> c.y1 >> c.z1 >> c.x2 >> c.y2 >> c.z2;
		for (x = c.x1; x < c.x2; x++) {
			for (y = c.y1; y < c.y2; y++) {
				for (z = c.z1; z < c.z2; z++) {
					a[x][y][z] = i + 1;
				}
			}
		}
	}
	vector<set<long long>> vans(n);
	rep(x, 100) {
		rep(y, 100) {
			rep(z, 99) {
				cur = a[x][y][z];
				res = a[x][y][z + 1];
				if (cur > 0 && res > 0 && cur != res) {
					vans[cur - 1].insert(res - 1);
					vans[res - 1].insert(cur - 1);
				}

				cur = a[y][z][x];
				res = a[y][z + 1][x];
				if (cur > 0 && res > 0 && cur != res) {
					vans[cur - 1].insert(res - 1);
					vans[res - 1].insert(cur - 1);
				}

				cur = a[z][x][y];
				res = a[z + 1][x][y];
				if (cur > 0 && res > 0 && cur != res) {
					vans[cur - 1].insert(res - 1);
					vans[res - 1].insert(cur - 1);
				}
			}
		}
	}

	rep(i, n) {
		cout << vans[i].size() << endl;
	}


}