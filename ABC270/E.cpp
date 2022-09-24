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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n >> k;
	vector<long long> a(n);
	multiset<long long> ms;
	rep(i, n) {
		cin >> a[i];
		ms.insert(a[i]);
	}

	cur = 0; res = 0;
	auto itr = ms.begin();
	while (!ms.empty()) {
		itr = ms.begin();
		res = *itr - cur;
		if (res * ms.size() < k) {
			k -= res * ms.size();
			cur += res;
			ms.erase(*itr);
		}
		else {
			cur += k / ms.size();
			res = k % ms.size();
			break;
		}
	}

	rep(i, n) {
		if (a[i] <= cur) {
			a[i] = 0;
		}
		else if (a[i] > cur && res > 0) {
			a[i] -= (cur + 1);
			res--;
		}
		else {
			a[i] -= cur;
		}
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}