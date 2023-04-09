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
	cin >> h >> w;
	vector<string> s(h);
	ans = 0;
	rep(i, h) {
		cin >> s[i];
		cur = 0; j = 0;
		while (j < w - 1) {
			if (s[i][j] == 'T' && s[i][j + 1] == 'T') {
				s[i][j] = 'P';
				s[i][j + 1] = 'C';
				j += 2;
			}
			else {
				j++;
			}
		}
	}

	rep(i, h) {
		cout << s[i] << endl;
	}
	
}