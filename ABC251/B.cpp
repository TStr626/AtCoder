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
	cin >> n >> w;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	set<long long> st;
	rep(i, n) {
		cur = a[i];
		if (cur <= w) {
			st.insert(cur);
		}
		for (j = i + 1; j < n;j++) {
			cur = a[i] + a[j];
			if (cur <= w) {
				st.insert(cur);
			}
			for (k = j + 1; k < n; k++) {
				cur = a[i] + a[j] + a[k];
				if (cur <= w) {
					st.insert(cur);
				}
			}
		}
	}
	cout << st.size() << endl;
}