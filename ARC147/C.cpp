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

struct range {
	long long val;
	long long elm;
};
bool operator<(range a, range b) {
	if (a.val != b.val) {
		return a.val < b.val;
	}
	else {
		return a.elm < b.elm;
	}
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<range> rng(2 * n);
	vector<long long> lv(n), rv(n);
	rep(i, n) {
		cin >> lv[i] >> rv[i];
		rng[2 * i].val = lv[i];
		rng[2 * i].elm = 0;
		rng[2 * i + 1].val = rv[i];
		rng[2 * i + 1].elm = 1;
	}

	sort(rng.begin(), rng.end());
	sort(lv.begin(), lv.end());
	/*
	rep(i, 2 * n) {
		cout << rng[i].val << rng[i].elm << endl;
	}
	*/
	long long lfix, rfix, mov;

	cur = 0;
	rep(i, n - 1) {
		res = (lv[i + 1] - lv[i]) * (i + 1) * (n - 1 - i);
		cur += res;
	}
	ans = cur;

	lfix = n - 1;
	rfix = 0;
	mov = 1;
	rep(i, 2 * n - 1) {
		res = (rfix - lfix) * mov * (rng[i + 1].val - rng[i].val);
		cur += res;
		ans = min(cur, ans);
		//cout << cur << endl;
		if (rng[i + 1].elm == 0) {
			lfix--;
			mov++;
		}
		else {
			mov--;
			rfix++;
		}
	}
	cout << ans << endl;

}