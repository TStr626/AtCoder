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

struct bomb {
	long long p;
	long long x;
	long long y;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	vector<string> s(8);
	rep(i, 8) {
		cin >> s[i];
	}
	rep(i, 8) {
		rep(j, 8) {
			if (s[i][j] == '*') {
				cout << char(j + 'a');
				cout << int(8 - i) << endl;
			}
		}
	}
}