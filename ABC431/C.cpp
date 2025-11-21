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
	cin >> n >> m >> k;
	vector<long long> vh(n), vb(m);
	rep(i, n) {
		cin >> vh[i];
	}
	rep(j, m) {
		cin >> vb[j];
	}
	sort(vh.begin(), vh.end());
	sort(vb.begin(), vb.end());
	jud = 1;
	rep(i, k) {
		if (vh[i] > vb[m - k + i]) {
			jud = 0;
		}
	}
	jud ? yes() : no();
}