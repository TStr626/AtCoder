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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	multiset<long long> ms;
	rep(i, n) {
		ms.insert(a[i]);
	}

	ans = 0;
	auto itr = ms.begin();
	while (ms.size() > 1) {
		itr = ms.begin();
		cur = *itr;
		itr = ms.end();
		itr--;
		res = *itr;
		ms.erase(itr);
		res %= cur;
		ans++;
		if (res > 0) {
			ms.insert(res);
		}
	}
	cout << ans << endl;
}