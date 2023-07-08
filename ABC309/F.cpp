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
#include<atcoder/segtree>
using namespace atcoder;

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

vector<int> compress(vector<int> a, int begin_value) {
	// need <map>,<algorithm>
	int i, n = a.size();
	map<int, int> mp;
	auto b = a;
	sort(b.begin(), b.end());
	int cur, res;
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

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return (int)(0);
}

struct pos {
	int x;
	int y;
};


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<vector<int>> b(n, vector<int>(3));
	rep(i, n) {
		rep(j, 3) {
			cin >> b[i][j];
		}
		sort(b[i].rbegin(), b[i].rend());
	}
	sort(b.rbegin(), b.rend());

	// compress b[i][1]
	vector<int> c(n);
	rep(i, n) {
		c[i] = b[i][1];
	}
	auto d = compress(c, 0);
	rep(i, n) {
		b[i][1] = d[i];
	}
	/*
	rep(i, n) {
	  rep(j, 3){
		cout << b[i][j] << ' ';
	  }
	  cout << endl;
	}
	*/

	segtree<int, op, e> sg(n + 1);
	queue<pos> qu;
	pos p;
	qu.push({ b[0][1],b[0][2] });
	rep(i, n - 1) {
		if (b[i][0] > b[i + 1][0]) {
			while (qu.size()) {
				p = qu.front();
				qu.pop();
				sg.set(p.x, max(p.y, sg.get(p.x)));
				//cout << p.x << ' ' << sg.get(p.x) << endl;
			}
		}
		if (sg.prod(b[i + 1][1] + 1, n + 1) > b[i + 1][2]) {
			yes();
			return 0;
		}
		qu.push({ b[i + 1][1],b[i + 1][2] });
	}

	no();
}