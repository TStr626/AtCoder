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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	string s;
	cin >> s;
	n = 8;
	cur = -1;
	rep(i, n) {
		if (s[i] == 'B') {
			if (cur == -1) {
				cur = i % 2;
			}
			else {
				if (cur == i % 2) {
					no();
					return 0;
				}
			}
		}
	}

	res = 0;
	rep(i, n) {
		if (s[i] == 'R') {
			res++;
		}
		if (s[i] == 'K') {
			if (res != 1) {
				no();
				return 0;
			}
		}
	}

	yes();
}