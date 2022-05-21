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
	cin >> n >> k;
	vector<long long> a(n), b(k);
	set<long long> st;
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, k) {
		cin >> b[j];
		st.insert(b[j] - 1);
	}

	cur = 0;
	rep(i, n) {
		cur = max(cur, a[i]);
	}

	jud = 0;
	rep(i, n) {
		if ((a[i] == cur) && st.count(i)) {
			jud = 1;
		}
	}

	if (jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}