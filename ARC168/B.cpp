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
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000000000000000;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	// regular nim
	cur = 0;
	rep(i, n) {
		cur ^= a[i];
	}
	if (cur) {
		cout << -1 << endl;
		return 0;
	}

	// arbitrary nim
	set<long long> st;
	rep(i,n) {
		if(st.count(a[i])){
			st.erase(a[i]);
		}
		else {
			st.insert(a[i]);
		}
	}
	if (st.size() == 0) {
		cout << 0 << endl;
	}
	else {
		cur = *st.rbegin();
		cout << cur - 1 << endl;
	}
	
}