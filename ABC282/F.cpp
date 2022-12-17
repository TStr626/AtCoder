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

struct range {
	long long l; // 0-indexed
	long long r; // 1-indexed
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long query;
	cin >> n;
	vector<long long> vsiz(0);
	cur = n;
	res = 0;
	while (true) {
		cur = (cur + 1) / 2;
		vsiz.push_back(cur);
		res += n - cur + 1;
		if (vsiz[vsiz.size() - 1] == 1) {
			break;
		}
	}
	vector<long long> vsum(vsiz.size());
	vsum[0] = 0;
	for (i = 1; i < vsiz.size(); i++) {
		vsum[i] = vsum[i - 1] + (n - vsiz[i - 1] + 1);
	}


	vector<range> vr(0);
	x = vsiz.size();
	range rg;
	rep(i, x) {
		cur = vsiz[i];
		for (j = 0; j + cur <= n; j++) {
			rg.l = j;
			rg.r = j + cur;
			vr.push_back(rg);
		}
	}

	//output1
	cout << res << endl;
	rep(i, res) {
		cout << vr[i].l + 1 << ' ' << vr[i].r << endl;
	}

	cin >> query;
	long long a, b;
	while (query--) {
		cin >> x >> y;
		x--;
		cur = y - x;
		i = 0;
		while (vsiz[i] > cur) {
			i++;
		}
		a = vsum[i] + x ;
		b = vsum[i] + (y - vsiz[i]);
		cout << a + 1 << ' ' << b + 1 << endl;
		//cout << vr[a].l + 1 << ' ' << vr[a].r << ' ' << vr[b].l + 1 << ' ' << vr[b].r << endl;
	}
	
}